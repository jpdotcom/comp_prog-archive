import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
 
def main(arr,arrows):



  for i in range(1,len(arr)):
      arr[i]=arr[i-1]+arr[i] 
  max_val=arr[-1] 
  if arrows[0]>=max_val:
    arrows[0]=0
  for i in range(1,len(arrows)):
    next_val=arrows[i-1]+arrows[i]
    
    arrows[i]= next_val if next_val<max_val else 0
  
  n=len(arr)
  for e in arrows:
    
    curr=e
    l=0 
    r=len(arr)-1
    ans=-1
    while l<=r:

      m=(l+r)//2 

      if arr[m]==curr:
        ans=(n-1)-(m)
        break 
      elif arr[m]<curr:
        ans=(n-1)-(m)
        l=m+1 
        
      else:
        r=m-1
     
    if ans==0 or ans==-1:
      print(n)
    else:
      print(ans)
  return 

n,k=list(map(int,input().split()))
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
(main(arr1,arr2))



