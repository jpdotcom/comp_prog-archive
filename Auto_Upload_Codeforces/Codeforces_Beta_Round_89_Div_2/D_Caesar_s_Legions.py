import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(n1,n2,k1,k2):

  mod=10**8
  dp=[[[0 for i in range(2)] for j in range(n2+1)] for k in range(n1+1)]

  dp[0][0][1]=1 
  dp[0][0][0]=1
  for i in range(0,len(dp)):
    for j in range(0,len(dp[0])):
      for k in range(0,len(dp[0][0])):

        if k==0:
          for l in range(1,min(k1+1,i+1)):
            dp[i][j][k]+=dp[i-l][j][1]


        if k==1:
          for l in range(1,min(k2+1,j+1)):
            dp[i][j][k]+=dp[i][j-l][0]
        
        dp[i][j][k]%=mod
  return sum(dp[-1][-1])%mod

n1,n2,k1,k2=list(map(int,input().split()))
print(main(n1,n2,k1,k2))




   



 