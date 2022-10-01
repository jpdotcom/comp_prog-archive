import sys
import math

def main(arr,m):
    
    
    dp=[[False]*(m+1) for i in range(len(arr)+1)]
    
    dp[0][0]=True
   
    for i in range(1,len(dp)):
        for j in range(len(dp[0])):
            
            dp[i][j]=dp[i-1][j] 
            
            if j-arr[i-1]>=0:
                dp[i][j]=dp[i][j] or dp[i-1][j-arr[i-1]]
    
    if dp[-1][-1]:
        return "Yes"
    return "No"


for _ in range(int(input())):
    n,m=input().split()
    n=int(n)
    m=int(m)
    arr=[]
    for j in range(n):
        arr.append(int(input()))
    print(main(arr,m))
                

        