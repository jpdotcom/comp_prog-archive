import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n):

  if n%2==0:
    print("NO")
    return
  arr=[0]*(2*n) 
  a=1 
  b=2
  for i in range(n):
    arr[i]=a
    arr[i+n]=b

    a+=2 
    b+=2 
    a,b=b,a
  print('YES')
  print(*arr)
  return

n=int(input())
(main(n))





