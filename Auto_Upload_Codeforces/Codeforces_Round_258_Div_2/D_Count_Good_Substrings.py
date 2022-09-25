
import math 
import sys
from decimal import Decimal


def main(arr):

  last_occ=[None,None]
  dp=[]
  for i in range(len(arr)):
    dp.append([0,1])
  
  if arr[0]=='a':
    last_occ[0]=0
  else:
    last_occ[1]=0 
  for i in range(1,len(arr)):
    
    a,b=dp[i] 
    l=0 if arr[i]=='a' else 1 
    if last_occ[l]!=None:
      c,d=dp[last_occ[l]]
      m=(i-last_occ[l])%2 
      if m:
        a+=d 
        b+=c 
      else:
        a+=c 
        b+=d 
    dp[i]=[a,b] 
    last_occ[l]=i
  
  e=0 
  o=0 
  for a,b in dp:
    e+=a 
    o+=b 
  print(e,o) 
  return
        

s=input()
main(s)
  








      

    








  




      


      
  
    






  
  
