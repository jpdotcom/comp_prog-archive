import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n):

  arr=[True]*(n+1)

  last_length=n 
  val=2
  c=False
  
  ans=[]

  for i in range(1,len(arr)):
    if arr[i]:
      temp=0 
      if last_length==3:
        c=True
        break
      for j in range(i,len(arr),val):
        arr[j]=False
        
        last_length-=1
        temp+=1 
   
      for k in range(temp):
        ans.append(val//2)
      val*=2
  last_val=None
  
  for i in range(len(arr)-1,-1,-1):
    if arr[i]:
      last_val=i 
      break
  if c:
    ans.append(val//2)
    ans.append(val//2)
    ans.append(last_val)

  print(*ans)

n=int(input())
main(n