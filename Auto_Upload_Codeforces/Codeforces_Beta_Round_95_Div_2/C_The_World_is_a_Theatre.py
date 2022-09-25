import math
import random 
from queue import Queue
import time 



def main(n,m,t):
  ans=0

  for i in range(1,t+1):
      
      if i>=4 and i<=n and (t-i)>=1 and (t-i)<=m:

        ans+=math.comb(n,i)*math.comb(m,t-i) 
  return ans

a,b,t=list(map(int,input().split()))
print(main(a,b,t))
   