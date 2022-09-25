
import math 
import sys
from decimal import Decimal

def main(arr):

  ans=0
  arr.sort()
  for i in range(len(arr)):

    val=arr[i] 
    inv=1-arr[i]
    for j in range(i+1,len(arr)):
      if val<=inv:
        val=(1-arr[j])*val+arr[j]*inv 
        inv*=(1-arr[j])
    ans=max(ans,val)
  print(ans) 
  return 
n=int(input())
arr=list(map(float,input().split()))
(main(arr))
    






        


      
     