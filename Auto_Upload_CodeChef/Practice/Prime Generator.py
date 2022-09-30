import sys
import math

import math
def sieve(l,primes):

  mark=[True]*(l+1)
  for i in range(2,l+1):

    if mark[i]:
      primes.append(i)
      for j in range(i**2,l+1,i):
        
        mark[j]=False
  

  return

def generate(low,high):

  primes=[]
  sieve(int(math.sqrt(high))+1,primes)
  
  new=[True]*(high-low+1)
  
  for e in primes:
    
      start=int(low/e)*e

      if start<low:
        start+=e
    
      
      
      for i in range(start,high+1,e):
        
        if i!=e:
          
          new[i-low]=False
 
  for i in range(len(new)):
    if new[i] and i+low>1:
      print(i+low)
     
  return 


for i in range(int(input())):
    
    a,b=list(map(int,input().split()))
    
    (generate(a,b))
    print("")