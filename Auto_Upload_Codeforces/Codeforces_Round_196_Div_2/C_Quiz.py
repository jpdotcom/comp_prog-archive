import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
from decimal import *
sys.setrecursionlimit(3000)
def f(n,c,k):
  mod=10**9+9
  l=0 
  r=n+1 
  x=n+1
  while l<=r:

    m=(l+r)//2 
    val1=Decimal((c-m*k))
    val2=Decimal(str((k-1)))
    
    val=math.ceil(c+val1/val2)
   
    if val==n+1:
      x=m 
      r=m-1 
    elif val>n+1:
      l=m+1 
     
    else:
      r=m-1
      x=m 

  
  c-=x*k
  
  return (max(0,c)+ (k*(pow(2,x+1,mod)-2)))%mod
n,m,k=list(map(int,input().split()))
print(f(n,m,k)) 


  









    



   



 