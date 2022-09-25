import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr,k):

  arr.sort(reverse=True) 

  prefix=[] 
  cnt={} 
  prefix.append(arr[0])
  

  for i in range(1,len(arr)):
    prefix.append(arr[i]+prefix[-1])
  cnt={}

  for e in arr:
    if e not in cnt:
      cnt[e]=0 
    cnt[e]+=1 
  seen=set()
  occ,num=-1,None
  
  for i in range(len(arr)):
    e=arr[i] 
  

    l=i+1
    r=len(arr)-1
    best=i
    while l<=r: 
      
      
      m=(l+r)//2 
      
      val=e*(m-i)-(prefix[m]-prefix[i])
      if val==k:
        best=m
        l=m+1
        
      elif val<k:
        best=m 
        l=m+1 
      else:
        r=m-1 
   
    ans=best-i+1
    
    if ans>=occ:
      occ=ans 
      num=e
      
  print(occ,num)
  return
    

  
n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))

(main(arr,k))

   



 