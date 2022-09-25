import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def main(n,a,b):
 
  a,b=b,a

  if n==1:
    print(1)
    return
  if a==0 and a+b+2>n and b!=0:
    print(-1)
    return 
  
  c=2 if a==0 else 1
  arr=[1,1] if a==0 else [2]
 
    
  curr_sum=arr[0]
 
  for i in range(a):
    
    arr.append(curr_sum+1)
    curr_sum+=arr[-1]
   
  for i in range(b):
    arr.append(arr[-1]+1)
 
  for i in range(n-a-b-c):
    arr.append(1)
  print(*arr)        
    

    
    


  return

n,a,b=list(map(int,input().split()))
(main(n,a,b))






