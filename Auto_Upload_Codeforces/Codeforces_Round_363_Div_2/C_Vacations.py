import math


def main(arr):


    dp=[[float('inf') for j in range(3)] for i in range(len(arr))]
    dp[0][0]=1 
    dp[0][1]=0 if (arr[0]==1 or arr[0]==3) else float('inf')
    dp[0][2]=0 if (arr[0]==2 or arr[0]==3) else float('inf')
    for i in range(1,len(dp)):
        for j in range(len(dp[0])):
            if j==0:
                dp[i][j]=1+min(dp[i-1][0],dp[i-1][1],dp[i-1][2])
            elif j==1:
                if arr[i]==1 or arr[i]==3:
                    
                    dp[i][j]=min(dp[i-1][0],dp[i-1][2])
            else:
                if arr[i]==2 or arr[i]==3:
                    dp[i][j]=min(dp[i-1][0],dp[i-1][1])
    
    return min(dp[-1])

n=int(input())
arr=list(map(int,input().split()))
print(main(arr))






    


