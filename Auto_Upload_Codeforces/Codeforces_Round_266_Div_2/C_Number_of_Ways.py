import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr):


  prefix=[arr[0]] 
  
  cnt={} 
  cnt[arr[0]]=[0]
  for i in range(1,len(arr)):
    val=arr[i]+prefix[-1]
    prefix.append(val) 
    if i!=len(arr)-1:

      if val not in cnt:
        cnt[val]=[]  
      cnt[val].append(i)
  s=prefix[-1]/3 
  if s!=int(s) or s not in cnt or 2*s not in cnt:
    return 0 
  else:
    s=int(s) 
  if s==0:
    
    a=len(cnt[s])
    return (a*(a-1))//2
  
  l1=cnt[s]
  l2=cnt[2*s] 
  ans=0
  for e in l1:
    
    l=0
    r=len(l2)-1
    found=None 
    while l<=r:
      m=(l+r)//2 
      if l2[m]==e+1:
        found=m
        break 
      elif l2[m]<(e+1): 
        l=m+1
      else:
        found=m 
        r=m-1
    if found!=None:
      ans+=len(l2)-found 
  return ans

n=int(input())
arr=list(map(int,input().split()))
print(main(arr))
    
        





    



   



 