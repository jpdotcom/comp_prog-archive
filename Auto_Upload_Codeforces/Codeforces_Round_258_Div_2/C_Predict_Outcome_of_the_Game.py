import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n,k,d_1,d_2):

  
  
  for i in range(4):
    
    d_1_copy=-1*d_1 if i==1 or i==2 else d_1 
    d_2_copy=-1*d_2 if i==1 or i==3 else d_2 
   
    c=(k-d_1_copy-2*d_2_copy)/3 
    b=d_2_copy+c
    a=d_1_copy+b
    
    if not (a==int(a) and b==int(b) and c==int(c) and a>-1 and b>-1 and c>-1):
      continue
    
    teams=[a,b,c] 
    teams.sort() 

    g=n-k 

    required=teams[-1]-teams[0]+teams[-1]-teams[1] 

    if g<required:
      continue
    g-=required 

    if g%3==0:
      return 'yes'
  return 'no'

t=int(input())
arr=[]
for i in range(t):
  n,k,d_1,d_2=list(map(int,input().split()))
  arr.append((main(n,k,d_1,d_2)))
for e in arr:
  print(e)


    
  







  
  

  
  







