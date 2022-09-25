
import math 
import sys
from decimal import Decimal


def main(k):

  val=math.sqrt(k)
  if val!=int(val):
    val=int(val)+1 
  else:
    val=int(val)
  start=(val,1)
 

  if val**2-(val-1)<k:

    diff=val**2-k
    start=val,1+diff 
    
    return start
  
  start=val,val  
  diff=val**2-(val-1)-k 
  start=val-diff,val 
  
  return start

n=int(input())
ans=[]
for i in range(n):
  ans.append(main(int(input())))
for e in ans:
  print(*e)
    





    

  
  
  








      

    








  




      


      
  
    






  
  
