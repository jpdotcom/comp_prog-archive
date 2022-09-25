import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n):

  f=[]
  for i in range(1,int(math.sqrt(n))+1):
    a=n/i 
    b=i 

    if a==int(a):
      f.append(int(a)) 
      if b!=a:
        f.append(b) 
  
  a=0 
  b=len(f)-1 
  f.sort()
  while a<=b:
    f1,f2=f[a],f[b] 
    for i in range(2):
      if i:
        f1,f2=f2,f1
       
      val1=9*f1**2-12*(f1**2-f2)
      
      if val1>=0:
        
        x1=(3*f1+math.sqrt(val1))/6
        if x1>0:
          x2=(f1**2-f2)/(3*x1) 
        if x1==int(x1) and x2==int(x2) and x1>0 and x2>0:
          
          return "YES"
        

        x1=(3*f1-math.sqrt(val1))/6
        if x1>0:
          x2=(f1**2-f2)/(3*x1) 
        if x1==int(x1) and x2==int(x2) and x1>0 and x2>0:
          
          return "YES"
    a+=1 
    b-=1 
  return "NO"
t=int(input())
ans=[]
for i in range(t):

  x=int(input())
  ans.append(main(x))
for e in ans:
  print(e)



