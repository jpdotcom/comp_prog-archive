import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n,intervals):

  smallest_dist=float('inf')

  for e in intervals:
    a,b=e
    smallest_dist=min(smallest_dist,(b-a+1))  

  arr=[] 
  val=0
  while len(arr)!=n:

    arr.append(val)
    val=(val+1)%smallest_dist 
  print(smallest_dist)
  print(*arr)
  return 

n,m=list(map(int,input().split()))
arr=[]
for i in range(m):
  arr.append(list(map(int,input().split())))
main(n,arr)

  

  
  







