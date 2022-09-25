import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def steps(arr):
  ind=set([]) 
  l=0
  r=0
  arr.append(-1)
  for i in range(1,len(arr)-1):
    
    if arr[i+1]==arr[i] and arr[i]==arr[i-1]:
      r=i+1
    else:
     
      if (r-l+1)>=3:

        for j in range(l,r+1):
          ind.add(j) 
      l=i
      r=l

  new_arr=[] 
  ans=0 
  for i in range(len(arr)):
    if i not in ind:
      new_arr.append(arr[i])
    else:
      ans+=1
  
  if ans==0:
    return 0 
  return ans+steps(new_arr)
      



def main(arr,x):

  orig_arr=arr.copy()
  ans=0
  for i in range(1,len(arr)):

    if arr[i]==arr[i-1] and arr[i]==x:
      arr.insert(i+1,x)
      s=steps(arr)
      ans=max(ans,s-1) 
    arr=orig_arr.copy()
  return ans

n,k,x=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,x))

    


