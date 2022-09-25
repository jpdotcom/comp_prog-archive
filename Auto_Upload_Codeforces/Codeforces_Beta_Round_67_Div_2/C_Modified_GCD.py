import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(a,b,qu):


  d=math.gcd(a,b)

  factors=[] 
  for i in range(1,int(math.sqrt(d))+1):
    
    q=d/i 
    if q==int(q):
      factors.append(int(q))
      factors.append(i) 
  factors.sort() 

  for e in qu:
   
    mi,ma=e 
    l=0
    h=len(factors)-1
    best_val=l
    while l<=h:
     
      m=(l+h)//2 
      val=factors[m]
      if val==ma:
        best_val=m
        break
      elif val<ma:
        l=m+1 
        best_val=m 
      else:
        h=m-1 
    if mi<=factors[best_val] and factors[best_val]<=ma:
      print(factors[best_val])
    else:
      print("-1")
  return
a,b=list(map(int,input().split()))
n=int(input())
arr=[]
for i in range(n):
  arr.append(list(map(int,input().split())))
main(a,b,arr)

  
  







