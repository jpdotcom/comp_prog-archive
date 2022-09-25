import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def getprimes():


  nums=[True]*(10**6+1)


  for i in range(2,len(nums)):

    if nums[i]:

      for j in range(i**2,len(nums),i):
        nums[j]=False 
  ans=[]
  for i in range(2,len(nums)):
    if nums[i]:
      ans.append(i)
  
  return ans 
def main(arr):

  primes=set(getprimes()) 


  for e in arr:
    val=math.sqrt(e)

    if val==int(val) and val in primes:
      print("YES")
    else:
      print("NO")
  return 

n=int(input())
arr=list(map(int,input().split()))
main(arr)

