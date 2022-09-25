
import math 
import sys
from decimal import Decimal


def main(a,b,c):

  if a>b:
    a,b=b,a
  n=2*(b-a)
  if c>n or b>n or a>n:
    return -1
  ans=(c+n//2)%n 
  if ans==0:
    return n  
  return ans

t=int(input())
ans=[]
for i in range(t):
  a,b,c=list(map(int,input().split()))
  ans.append(main(a,b,c))
for e in ans:
  print(e)  





    

  
  
  








      

    








  




      


      
  
    






  
  
