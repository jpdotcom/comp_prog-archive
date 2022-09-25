import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def u(a):

  freq={}
  for e in a:
    if e not in freq:
      freq[e]=0
    freq[e]+=1 
  for e in freq:
    if freq[e]>1:
      return False 
  return True
def main(q):
  
  ans=[]
  for i in range(1,10000):

    s=[c for c in str(i)]
   
    if len(s)!=4:
      s=["0"]*(4-len(s))+s 
    if u(s):
      
      w=True
      for e in q:

        s2,b,c=e 
        s2=[c for c in str(s2)]
        
        if len(s2)!=4:
          s2=["0"]*(4-len(s2))+s2 
        for k in range(len(s)):
          if s[k]==s2[k]:
            b-=1 
          else:
            if s[k] in s2:
              
              c-=1 
        
        if c!=0 or b!=0:
          w=False 
          break 
      if w:
        ans.append(s) 
      
      
  
  if len(ans)==1:
    print("".join(ans[0]))
  elif len(ans)==0:
    print('Incorrect data')
  else:
    print("Need more data")
  return 

n=int(input())
arr=[]
for i in range(n):
  arr.append(list(map(int,input().split())))


main(arr)


