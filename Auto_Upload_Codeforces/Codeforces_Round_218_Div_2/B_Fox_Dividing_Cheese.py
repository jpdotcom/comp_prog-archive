import math
import random 
from queue import Queue
import time 


def bd(n,m):

  ans=0

  while n//m==n/m :
    ans+=1 
    n//=m 
	
  return n,ans
def main(a,b):

  
  s2=bd(a,2)
  
  s3=bd(s2[0],3)

  s5=bd(s3[0],5)

  t2=bd(b,2)

  t3=bd(t2[0],3)

  t5=bd(t3[0],5)

  if s5[0]!=t5[0]:
    return -1 
  
  else:
    return abs(t2[1]-s2[1])+abs(t3[1]-s3[1])+abs(t5[1]-s5[1])

a,b=list(map(int,input().split()))
print(main(a,b))
   