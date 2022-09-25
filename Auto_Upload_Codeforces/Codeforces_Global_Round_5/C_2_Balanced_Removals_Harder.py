import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
 
def main(arr):


  axis={} 
  if len(arr[0])==2:
    arr.sort(key=lambda x:x[-1])
    val1=len(arr)//2
    
    for i in range(0,len(arr)-1,2):
      print(arr[i][0],arr[i+1][0])
    if len(arr)%2==0:
      val2=None 
    else:
      val2=arr[-1]
    
    return val1,val2
  for e in arr:
    
    a=e[-1]

    b=e[0:len(e)-1] 

    if a not in axis:
      axis[a]=[] 
    axis[a].append(b)
  
  last_points=[]
  ans=0
  for e in axis:

    val1,val2=main(axis[e])
    ans+=val1 
 
    if val2:
      last_points.append(val2+[e])
  
  last_points.sort(key=lambda x:x[-1])
  
  new1=ans+len(last_points)//2
  new2=None
  for i in range(0,len(last_points)-1,2):
      print(last_points[i][0],last_points[i+1][0])
  if len(last_points)%2==1:
    new2=last_points[-1] 
  
  return new1,new2 

n=int(input())
arr=[] 
for i in range(n):
  arr.append([i+1]+list(map(int,input().split())))
(main(arr))
  



