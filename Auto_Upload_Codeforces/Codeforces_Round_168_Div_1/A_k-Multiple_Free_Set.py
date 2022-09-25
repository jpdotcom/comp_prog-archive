import math
import random 
from queue import Queue
import time 



def main(arr,k):

  set_arr=set(arr)
  max_val=max(arr)
  min_val=min(arr)
  arr.sort()
  if k==1:
    return len(set_arr)
  f={}
  for e in arr:
    if e not in f:
      f[e]=0
    f[e]+=1
  ans=0
  for e in arr:
    if e in set_arr:


      new_arr=[] 
      start_max=e

      
      while start_max<=max_val:
        if start_max in set_arr:
          set_arr.remove(start_max)
          new_arr.append(f[start_max])
        else:
          new_arr.append(0)

        start_max*=k
      
      dp=[[0 for j in range(2)] for i in range(len(new_arr))]
      dp[0][0]=0 
      dp[0][1]=new_arr[0]

      for i in range(1,len(dp)):
        for j in range(len(dp[0])):

          if j==0:
            dp[i][j]=max(dp[i-1][0],dp[i-1][1])
          else:
            dp[i][j]=new_arr[i]+dp[i-1][0]
      ans+=max(dp[-1])
  return ans 

  

n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,k)