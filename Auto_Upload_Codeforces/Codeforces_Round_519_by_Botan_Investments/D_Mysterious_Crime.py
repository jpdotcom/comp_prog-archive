
import math 
import sys
from decimal import Decimal

def main(arr,n,m):


  idx=[[0 for i in range(n+1)] for j in range(m)]

  if m==1:
    return n*(n+1)//2
  

  new=True
  l=0
  for i in range(m):
    for j in range(n):
      idx[i][arr[i][j]]=j
  curr_idx=[0]*m 
  ans=0
  i=0 
  
  while i<len(arr[0]):
    val=arr[0][i]
    
    if new:
      
      new=False
    
      for j in range(m):
        
        curr_idx[j]=idx[j][val]
      l=1
    else:
      
      for j in range(m):

        if idx[j][val]!=curr_idx[j]+1:
          ans+=l*(l+1)//2
          new=True
          i-=1
          break 
        else:
          curr_idx[j]+=1
      if not new:
        l+=1
    i+=1
    
 
  if l>=1:
    ans+=l*(l+1)//2
  return ans

n,m=list(map(int,input().split()))
arr=[] 

for i in range(m):
  arr.append(list(map(int,input().split())))
print(main(arr,n,m))






    






        


      
     