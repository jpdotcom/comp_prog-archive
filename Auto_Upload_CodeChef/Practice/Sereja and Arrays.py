import sys
import math
from queue import Queue 
import heapq

def main(n,k):
    
    
    dp=[0]*(n+1)
    
    dp[0]=1 
    mod=10**9+7
    for i in range(1,n+1):
        
        if (i-k)>=0:
            dp[i]+=dp[i-k]
        dp[i]+=dp[i-1]
        dp[i]%=mod 
    return dp[-1]
    

t=int(input())
ans=[]
for i in range(t):
    n,k=list(map(int,input().split()))
    ans.append(main(n,k))
for e in ans:
    print(e)