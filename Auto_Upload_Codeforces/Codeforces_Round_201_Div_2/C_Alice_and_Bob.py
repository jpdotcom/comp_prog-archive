import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr):


  g=arr[0]

  for e in arr:
    g=math.gcd(g,e) 
  
  max_arr=max(arr) 

  s=max_arr//g-len(arr) 

  if s%2:
    return "Alice"
  return "Bob"
n=int(input())
arr=list(map(int,input().split()))
print(main(arr))





