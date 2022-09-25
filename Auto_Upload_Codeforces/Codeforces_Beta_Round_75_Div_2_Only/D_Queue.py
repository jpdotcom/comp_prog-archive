
import math 
import sys
from decimal import Decimal
def main(arr):


  minof=[0]*(len(arr))
      
  minof[-1]=[arr[-1],len(arr)-1]
  for i in range(len(arr)-2,-1,-1):
    a,b=minof[i+1]
    c=arr[i] 
    if a<=c:
      minof[i]=[a,b]
    else:
      minof[i]=[c,i] 
  ans=[]

  for i in range(len(arr)-1):
    
    
    val=arr[i] 
    l=i
    r=len(arr)-1 
    best=l
    while l<=r:
      m=(l+r)//2
      a,b=minof[m]
   
      if val>a:
        l=m+1
        best=m
      else:
        r=m-1
    ans.append(best-i-1)

  ans.append(-1)
  print(*ans)
  return 

n=int(input())
arr=list(map(int,input().split()))
(main(arr))

  
  
    






  
  
