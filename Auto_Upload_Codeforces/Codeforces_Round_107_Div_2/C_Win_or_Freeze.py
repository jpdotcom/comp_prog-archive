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
     

      factors.append(a)
      factors.append(b)
  factors.sort()
  if len(factors)==4 and not isPrime((q**(1/3))):
    print(2)
  else:
    print(1)
    if isPrime(q):

      print(0) 
    else:
      val1=factors[2]
      
      if isPrime(val1):
        
        print((val1*factors[1]))
      else:
        print(val1)
  return
    
    

q=int(input())
(main(q))
