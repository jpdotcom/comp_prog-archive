import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def getCost(x,inv,prices,ord_count):
  a,b,c=ord_count

  return max(prices[0]*(a*x-inv[0]),0) + max(prices[1]*(b*x-inv[1]),0) + max(prices[2]*(c*x-inv[2]),0)

def main(arr,p):

  cnt=[0]*len(arr)
  for i in range(len(arr)):
    l,r=arr[i]

    start=l if l%p==0 else l+(p-(l%p))
    
    add=0
    if start<=r:
      add+=1 
    x_nums=(r-start)/p 
    add+=int(x_nums)
    cnt[i]=add
  
  for i in range(len(cnt)):
    l,r=arr[i] 
    cnt[i]/=(r-l+1)
  prob=0 

  
  for i in range(len(arr)):
    prev=cnt[(i-1)%len(arr)]
    curr=cnt[i]

    
    prob+=curr+prev-curr*prev 

  return prob*2000 
n,p=list(map(int,input().split()))
arr=[]
for i in range(n):
  arr.append(list(map(int,input().split())))
print(main(arr,p))






  
  

  
  







