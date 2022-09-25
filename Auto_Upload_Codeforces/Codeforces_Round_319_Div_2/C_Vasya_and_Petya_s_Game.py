import math
import random 
from queue import Queue
import time 
def findnum(a,b):

  ans=0 
  
  while a%b==0:
    a/=b 
    ans+=1 
  return a,ans


def main(n):

  factors=set([]) 
  for i in range(2,n+1):
    
    curr=i
    for j in range(2,i+1):
      
      run=findnum(curr,j)
      need=int(j**run[1])
     
      if need==1:
        continue 
      elif need not in factors:
        factors.add(need)
        break 
      else:
        curr=run[0]

  print(len(factors))
  print(*factors)


  
n=int(input()) 
main(n