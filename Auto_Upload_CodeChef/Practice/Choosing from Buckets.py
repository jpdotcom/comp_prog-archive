import sys
import math

def main(arr):
    
    k=len(arr[0])
    n=len(arr)
    dp=[[0]*k for i in range(n+1)]
    
    summation_arr=[]
    for i in range(len(arr)):
        a=1 if i!=0 else 0
        summation_arr.append(sum(arr[i])+a)
    
    for i in range(1,len(dp)):
        for j in range(len(dp[0])):
            dp[i][j]=(dp[i-1][j]+arr[i-1][j])/summation_arr[i-1]
    ans=[]
    
    for i in range(k):
        ans.append(dp[-1][i])
    print(*ans)


    
n,k=input().split()
n=int(n)
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))
(main(arr))
    
    
        