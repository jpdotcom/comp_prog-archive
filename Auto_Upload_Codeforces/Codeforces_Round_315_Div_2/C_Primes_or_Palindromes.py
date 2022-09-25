import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def getprimes(n):

  arr=[True]*(n+1)

  for i in range(2,int(math.sqrt(n))+1):
    if arr[i]:
      for j in range(i**2,len(arr),i):
        arr[j]=False 
  
  primes=set()

  for i in range(2,len(arr)):
    if arr[i]:
      primes.add(i)
  return primes
def pa(n):

  n=str(n) 
  
  for i in range(len(n)//2):
    if n[i]!=n[len(n)-1-i]:
      return False 
  return True
def main(p,q):


  arr1=[]
  s=2*10**6
  arr2=getprimes(s) 
  arr=[0]
  arr1.append(0) 

  for i in range(1,s):
    val=1 if pa(i) else 0
    arr1.append(arr1[-1]+val)
  for i in range(1,s):
    val=1+arr[-1] if i in arr2 else arr[-1]
    arr.append(val)
  arr2=arr 
  best="Palindromic tree is better than splay tree"
  for i in range(len(arr1)):
    if p*arr1[i]>=q*arr2[i]:
      best=i 
  return best 

p,q=list(map(int,input().split()))
print(main(p,q))
 