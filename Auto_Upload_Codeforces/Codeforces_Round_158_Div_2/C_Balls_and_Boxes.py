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

  dist=0
  min_arr=min(arr)
  min_sub=float('inf')
  for i in range(len(arr)):

    if min_arr>=arr[start] and min_sub>=arr[start]+1:
      ans=sub(arr,arr[start]) 
      if dist!=0:

        j=(start+1)%len(arr) 

        while j!=x:
          
          ans[j]-=1 
          j=(j+1)%len(arr) 
        ans[x]-=1
      ans[start]+=(arr[start]*len(arr)+dist)
      print(*ans)
      return
    else:
      min_sub=min(min_sub,arr[start]) 
    start=(start-1)%len(arr)
    dist+=1
  

n,x=list(map(int,input().split()))
arr=list(map(int,input().split()))
main(arr,x)







