
import math 
import sys
from decimal import Decimal


def main(l,r):

  if l==r:
    return 0 

  val=1

  while val*2<=r:
    val*=2 
  
  if val<=l: 
    return main(l-val,r-val) 
  else:
    return 2*val-1 







      

    



l,r=list(map(int,input().split()))
print(main(l,r))




  




      


      
  
    






  
  
