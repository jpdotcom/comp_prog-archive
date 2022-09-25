
import math 
import sys
from decimal import Decimal


def main(k):

  s='1'
  k-=1
  while k:
    
    s=str(int(s)+1)
    k-=1
    while (s[-1]=='3' or int(s)%3==0):
      s=str(int(s)+1) 
      
  return int(s)
t=int(input())
ans=[]
for i in range(t):
  ans.append(main(int(input())))
for e in ans:
  print(e)

    
    


      





    

  
  
  








      

    








  




      


      
  
    






  
  
