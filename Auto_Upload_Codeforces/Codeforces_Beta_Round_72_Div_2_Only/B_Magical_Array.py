import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def main(arr):
  l,r=0,0
  ans=0
  arr.append(-float('inf'))
  for i in range(1,len(arr)):
   
    if arr[i]==arr[i-1]:
      
      r=i
     

    else:
     
      nums=r-l+1 
      ans+=nums*(nums+1)/2
      l=r=i
  return int(ans)
n=int(input())
arr=list(map(int,input().split()))
print(main(arr))
    
    


