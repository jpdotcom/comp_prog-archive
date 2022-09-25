import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr,k):

  


  greater=[0]*(max(arr)+1) 


  for i in range(len(arr)):
    if arr[i]-1>0:
      greater[arr[i]-1]+=1 
  
  for i in range(len(greater)-2,-1,-1):
    greater[i]+=greater[i+1]
  

  i=max(arr) 
  
  ans=0
  curr_sum=0
  for i in range(i,min(arr)-1,-1):
    
    if curr_sum+greater[i]<=k:
      curr_sum+=greater[i] 
    else:
      ans+=1 
      curr_sum=greater[i]
    i-=1
  if curr_sum!=0:
    ans+=1
  return ans
n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))

print(main(arr,k)) 






