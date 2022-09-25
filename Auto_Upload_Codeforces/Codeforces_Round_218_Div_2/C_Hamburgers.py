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

def main(order,inv,prices,r):


  l=0 
  h=10**13
  ans=0
  ord_count=[0]*3 
 
  for e in order:

    if e=='B':
      ord_count[0]+=1 
    elif e=="S":
      ord_count[1]+=1 
    else:
      ord_count[2]+=1
  
  while l<=h:


    m=(l+h)//2 

    cost=getCost(m,inv,prices,ord_count)
    
    if cost==r:
      ans=m 
      l=m+1 
    elif cost<r:
      ans=m 
      l=m+1 
    else:
      h=m-1 
  return ans 

ord=input() 
inv=list(map(int,input().split()))
prices=list(map(int,input().split()))
r=int(input())
print(main(ord,inv,prices,r))



  
  

  
  







