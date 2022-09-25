import math
import random 
from queue import Queue
import time 



def main(n,m,t):
  ans=0

  for i in range(4,n+1):
    for j in range(1,m+1):
      
      if  i+j==t:
        ans+=math.comb(n,i)*math.comb(m,j) 
  return ans

a,b,t=list(map(int,input().split()))
print(main(a,b,t))
   