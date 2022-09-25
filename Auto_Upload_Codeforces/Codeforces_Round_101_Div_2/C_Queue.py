import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr):
  arr.sort(key=lambda x:x[1])


  new_arr=[i for i in range(1,len(arr)+1)]

  new_arr.sort(reverse=True) 

  used=set() 
  n=len(arr)
  for i in range(len(arr)-1,-1,-1):
    
    name,val=arr[i] 

    start=n-val 

    while (start in used):
      start-=1 
    if start<=0:
      print(-1)
      return 
    else:
      new_arr[i]=start 
      used.add(start) 
  
  for i in range(len(arr)):
    print(arr[i][0],new_arr[i]) 
  return 





 
n=int(input())
arr=[] 
for i in range(n):
  a,b=input().split()
  b=int(b)
  arr.append([a,b])
(main(arr))






    



   



 