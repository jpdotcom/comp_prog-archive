import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def isPrime(q):
  if q!=int(q):
    return False
  for i in range(2,int(math.sqrt(q))+1):
    
    a=i 
    b=q//i 

    if b==q/i:
      return False
  return True

def main(q):
  factors=[]
  for i in range(1,int(math.sqrt(q))+1):
    
    a=i 
    b=q//i 

    if b==q/i:
     
      if a!=b:

        factors.append(a)
        factors.append(b)
      else:
        factors.append(b)
  factors.sort()
  if isPrime(q):
    print(1)
    print(0)
  else:
    val1=factors[1]
    val2=q/factors[1]
    if isPrime(val2):
      print(2)
      
    else:
      print(1)
      val2=factors[2]
      if isPrime(val2):
        print(val2*val1)
      else:
        print(val2)
  return

q=int(input())
(main(q))
