import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def sub(arr,val):

  ans=[arr[i]-val for i in range(len(arr))]
  return ans
def main(arr,x):


  x-=1 

  start=x 
  t=(None,float('inf'),None) 
  dist=0
  for i in range(len(arr)):

    a,b,c=t 

    if arr[start]<b:
      t=(start,arr[start],dist) 
    start=(start-1)%len(arr)
    dist+=1 
  a,b,c=t
  ans=sub(arr,arr[a]) 
  
  if a!=x:

    j=(a+1)%len(arr)

    while j!=x:

      ans[j]-=1 
      j=(j+1)%len(arr)
    ans[x]-=1
  
  ans[a]+=arr[a]*len(arr)+c 
  print(*ans)

    

  

n,x=list(map(int,input().split()))
arr=list(map(int,input().split()))
main(arr,x)







