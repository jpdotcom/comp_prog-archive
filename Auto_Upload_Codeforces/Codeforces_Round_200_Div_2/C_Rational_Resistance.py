import math
import random 
from queue import Queue
import time 



def main(a,b):

  ans=0
  while b!=0:
   
    ans+=a//b 
    
    a=a-(a//b*b) 
    a,b=b,a
  
  return ans

a,b=list(map(int,input().split()))
print(main(a,b)