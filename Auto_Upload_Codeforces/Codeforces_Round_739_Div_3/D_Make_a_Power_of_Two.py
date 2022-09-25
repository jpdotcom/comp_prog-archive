
import math 
import sys
from decimal import Decimal



def get_ans(start,k):


  start=str(start) 

  j=0
  p=0 
  n=0
  for i in range(len(start)):
    found=False
    while j<len(k):
      if start[i]==k[j]:
        found=True
        p+=1
        j+=1   
        break 
      
      j+=1
    if not found:
      n+=1
  
  return n+len(k)-p

def main(k):


  k=str(k) 
  start=1 
  ans=float('inf')
  while start<=10**20:

    ans=min(ans,get_ans(start,k))
    start*=2 
  return ans


n=int(input())
ans=[]
for i in range(n):
  ans.append(main(int(input())))
for e in ans:
  print(e)



    





    

  
  
  








      

    








  




      


      
  
    






  
  
