
import math 
import sys
def main(arr):


  neg=0 
  pos=0 
  if len(arr)==1:
    return arr[0]
  if len(arr)==2:
    return abs(arr[0]-arr[1])
  for e in arr:
    if e>0:
      pos+=e 
    else:
      neg+=-1*e 
  
  if pos==0:
    return pos+neg+2*max(arr)
  if neg==0:
    return pos+neg-2*min(arr)
  else:
    return pos+neg
n=int(input())
arr=list(map(int,input().split()))
print(main(arr)) 
      
     