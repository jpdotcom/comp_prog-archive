import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr,cost,c,m):


  dp=[[[float('inf') for l in range(m+1)] for j in range(c+1)] for i in range(len(arr)+1)]

  dp[0][0][0]=0 
  curr_min=[[] for d in range(c+1)]
  curr_min[0]=[[0,0],[-1,float('inf')]]
  for i in range(1,len(dp)):
    temp_min=[[] for d in range(c+1)]
    
    for j in range(1,len(dp[0])):
      
      for k in range(1,len(dp[0][0])):
        if arr[i-1]==0 or arr[i-1]==k:
          
          val=0 if arr[i-1]==k  else cost[i-1][k-1]
          
          if len(curr_min[j-1])==0:
            val2=float('inf')
          elif len(curr_min[j-1])==1:
            a=curr_min[j-1][0]
            
            val2=float('inf') if a[0]==k else a[1] 
          else:
            a,b=curr_min[j-1] 
           
            val2=a[1] if a[0]!=k else b[1]


          dp[i][j][k]=val+min(val2,dp[i-1][j][k])
          temp_min[j].append([k,dp[i][j][k]])
          temp_min[j].sort(key=lambda x:x[1])
          if len(temp_min[j])>2:

            temp_min[j].pop()
        
    curr_min=temp_min

  ans=min(dp[-1][-1])
 
  if ans==float('inf'):
    return -1
  return ans

n,m,k=list(map(int,input().split()))
arr=list(map(int,input().split()))
arr2=[]
for i in range(n):
  arr2.append(list(map(int,input().split())))
print(main(arr,arr2,k,m))



  


