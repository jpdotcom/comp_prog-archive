
import math 
import sys

def main(arr):
  

   

  

  ans=0
  for i in range(len(arr)):
    x1,y1=arr[i]
    points={}
    for j in range(len(arr)):

      if i!=j:

        x2,y2=arr[j] 
        e=float('inf')
        if x2-x1!=0:
          e=(y2-y1)/(x2-x1)
        if e not in points:
          points[e]=0
        points[e]+=1 
    s=0
    
    for p in points:
      s+=points[p] 
    for p in points:
      s-=points[p] 
      ans+=s*points[p]
    
  return ans//3

n=int(input())
arr=[]
for i in range(n):
  arr.append(list(map(int,input().split())))
print(main(arr))




        


      
     