import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n,k,d):

  mod=10**9+7
  dp=[[0 for i in range(2)] for i in range(n+1)] 


  dp[0][0]=1 

  for i in range(1,len(dp)):
    for j in range(len(dp[0])):
      if j==0:
       
        for b in range(1,min(k,i)+1):
          if b<d:

            dp[i][j]+=dp[i-b][j] 
            dp[i][j]%=mod
      if j==1 and i>=d:
        
        for b in range(1,min(k,i)+1):
          dp[i][j]+=dp[i-b][1]
          dp[i][j]%=mod
        for b in range(d,min(k,i)+1):
          dp[i][j]+=dp[i-b][0]
          dp[i][j]%=mod
  return dp[-1][-1]


   
n,k,d=list(map(int,input().split()))
print(main(n,k,d))


 