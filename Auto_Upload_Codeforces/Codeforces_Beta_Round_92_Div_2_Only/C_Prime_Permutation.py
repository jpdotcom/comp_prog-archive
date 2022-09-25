import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def get_primes(n):


  arr=[True]*(n+1)

  for i in range(2,int(math.sqrt(n))+1):

    if arr[i]:

      for j in range(i**2,len(arr),i):
        arr[j]=False 
  primes=[] 
  
  for i in range(2,len(arr)):
    if arr[i]:
      primes.append(i) 
  return primes
def main(s):

  n=len(s) 
  
  primes=get_primes(n) 

  cnt={} 
  prev=0
  for e in s:
    if e not in cnt:
      cnt[e]=0 
    cnt[e]+=1
  s=[0]*n
  tot=n-1
  remove=set()
  for p in primes:
    
    if 2*p>n: 
      tot-=1
      remove.add(p-1)
  
  b=0
  for e in cnt: 
    if tot<=cnt[e]:
      b=1
      idx=1
      nums_put=0
      while nums_put!=tot:

        if idx not in remove:
          s[idx]=e 
          nums_put+=1 
        idx+=1
      cnt[e]-=tot
      break 
  
  if not b:
    print("NO")
    return 
  left=[] 
  for e in cnt:
    if cnt[e]>0:
      for i in range(cnt[e]):
        left.append(e)
  
  idx=0 
  for i in range(len(s)):
    if not s[i]:
      s[i]=left[idx]
      idx+=1 
  print("YES")
  print("".join(s))
  return
  

        

s=input()
(main(s))

