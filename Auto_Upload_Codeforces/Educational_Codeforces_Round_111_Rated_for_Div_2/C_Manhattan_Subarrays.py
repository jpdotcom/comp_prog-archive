import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def isSorted(arr):
  s=((arr==sorted(arr)) or (arr==sorted(arr,reverse=True))) 
 
  return s
def main(arr):

  n=len(arr)
  ans=n+n-1 

  for i in range(1,len(arr)-1):

    a=arr[i-1]
    b=arr[i] 
    c=arr[i+1]

    if not(a>=b and b>=c) and not (a<=b and b<=c):
      ans+=1 
    
  
  for i in range(1,len(arr)-2):
    a=arr[i-1]
    b=arr[i]
    c=arr[i+1]
    d=arr[i+2] 
    
    if not isSorted([a,b,c]) and not isSorted([b,c,d]) and not isSorted([a,b,d]) and not isSorted([a,c,d]):
      ans+=1 
    
  return ans 

t=int(input())
ans=[]
for i in range(t):

  n=int(input())
  ans.append(main(list(map(int,input().split()))))

for e in ans:
  print(e)
   



 