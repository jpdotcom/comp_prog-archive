import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr):
  
  a,b=0,0
  idx=[]
  for i in range(len(arr)-1):
      
    if arr[i]!=arr[i+1]:
      b+=1 
    else:
    
      if (b-a+1)>2:

        idx.append((a,b))
      a=i+1 
      b=i+1
  if (b-a+1)>2:

    idx.append((a,b))
    a=i+1 
    b=i+1
  
  new_arr=arr.copy()
  ans=0 
  
  for e in idx:
    a,b=e
    
    ans=max(ans,(b-a)//2)
    if arr[a]==arr[b]:
      for i in range(a,b+1):
        new_arr[i]=arr[a] 
    else:
      r=False if arr[a]==0 else True
      
      temp_arr=arr[a:b+1]
      temp_arr.sort(reverse=r)
      j=0
      for i in range(a,b+1):
        new_arr[i]=temp_arr[j] 
        j+=1 
  print(ans)
  print(*new_arr)
n=int(input())
arr=list(map(int,input().split()))
(main(arr))
      



  


