import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
 
def main(arr,q):

  new_arr=[0]*200002
  for i in range(len(arr)):
    a,b=arr[i] 

    new_arr[a]+=1 
    new_arr[b+1]-=1
  for i in range(1,len(new_arr)):
    new_arr[i]+=new_arr[i-1]
  for i in range(len(new_arr)):
    new_arr[i]=1 if new_arr[i]>=k else 0
  
  for i in range(1,len(new_arr)):
    new_arr[i]+=new_arr[i-1]
  
  for a,b in q:
    print(new_arr[b]-new_arr[a-1])
n,k,m=list(map(int,input().split()))
arr=[] 
arr2=[] 
for i in range(n):
  arr.append(list(map(int,input().split())))
for i in range(m):
  arr2.append(list(map(int,input().split())))
main(arr,arr2)




