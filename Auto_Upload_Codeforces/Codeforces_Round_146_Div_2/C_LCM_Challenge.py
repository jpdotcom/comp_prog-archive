
import math
from os import curdir 
import sys
import itertools 
def lcm(a, b):
    return abs(a*b) // math.gcd(a, b)
def main(n):
  if n==1 or n==2:
    return n
  if (n%2):
    return n*(n-1)*(n-2) 
  
  ans=(n-3)*(n-1)*(n-2)  
  start=max(1,n-100)
  for i in range(start,n):
    for j in range(start,n):

      if i!=j:
        val=(lcm(lcm(i,j),n))
        ans=max(ans,val)
  return ans
print(main(int(input())))  
  



  


    





    

  
  
  








      

    








  




      


      
  
    






  
  
