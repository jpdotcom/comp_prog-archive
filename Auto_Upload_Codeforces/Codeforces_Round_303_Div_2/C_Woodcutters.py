import math


def main(arr):
    

    dp=[[0 for i in range(3)] for j in range(len(arr))]

    dp[0][0]=0 
    dp[0][1]=1 
    dp[0][2]=1 if (len(arr)<2) or (arr[1][1]+arr[0][0])<arr[1][0] else 0 

    for i in range(1,len(dp)):
       for j in range(len(dp[0])):
            tree=0
            if j==0:
                tree=max(dp[i-1][0],dp[i-1][1],dp[i-1][2])

            if j==1:
                occupied= arr[i][0]-arr[i][1]
                if occupied>arr[i-1][0]:
                    tree=max(dp[i-1][0]+1,dp[i-1][1]+1)

                    if arr[i-1][0]+arr[i-1][1]<occupied:
                        tree=max(tree,dp[i-1][2]+1)
            if j==2:
                occupied=arr[i][0]+arr[i][1]
                
                if (i==len(arr)-1) or (occupied<arr[i+1][0]):
                    
                    tree=max(dp[i-1][0]+1,dp[i-1][1]+1)
                    if arr[i-1][0]+arr[i-1][1]<occupied:
                            tree=max(tree,dp[i-1][2]+1)
            dp[i][j]=tree
    
    return max(dp[-1])
               

n=int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))
print(main(arr))



    


