import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def run(n,m,start):
  a=n+m 

  arr=[]
  turn=0
  left=[n,m]
  while a!=0:
    
    
    opt=start if turn%2==0 else start^1
    
    if left[opt]!=0:
      arr.append(opt)
      left[opt]-=1 
      start=opt
      
    else:
      arr.append(opt^1)
      left[opt^1]-=1 
      start=opt^1
    turn+=1
    a-=1
  return arr
def main(n,m):



  arr1=run(n,m,0)
  arr2=run(n,m,1)
  
  p1,v1=0,0
  p2,v2=0,0

  for i in range(len(arr1)-1):
    if arr1[i]==arr1[i+1]:
      p1+=1 
    else:
      v1+=1 
  for i in range(len(arr2)-1):
    if arr2[i]==arr2[i+1]:
      p2+=1 
    else:
      v2+=1
  
  if p1>p2:
    print(p1,v1)
    return
  print(p2,v2)
  return

n,m=list(map(int,input().split()))
(main(n,m))





