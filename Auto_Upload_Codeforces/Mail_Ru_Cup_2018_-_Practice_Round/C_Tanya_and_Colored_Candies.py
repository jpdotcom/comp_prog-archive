def main(arr1,arr2,s,k):

    for i in range(len(arr1)):
        arr1[i]=[arr1[i],i]

    arr1.sort(key=lambda x:x[0],reverse=True)
    dp=[[float('inf') for i in range(3000)] for j in range(100)]
    for i in range(len(arr1)+1):
        for j in range(len(dp[0])):
        
            if (j==0):
                dp[i][j]=0
            elif (i!=0):
                val,idx1=arr1[i-1]
                c=arr2[idx1]
                for l in range(i):
    
                    if (val>=j):
                        dp[i][j]=0;
    
                    elif (l==0):
    
                        dp[i][j]=min(dp[i][j],dp[0][j-val])

                    else:

                        val2,idx2=arr1[l-1]
                        if (c!=arr2[idx2] and val!=val2):

                             dp[i][j]=min(dp[i][j],dp[l][j-val]+abs(idx1-idx2))
    
    ans=float('inf')

    for i in range(1,len(arr1)+1):
        val,idx1=arr1[i-1]
        ans=min(ans,dp[i][k]+abs((s-1)-idx1))
    return ans if ans!=float('inf') else -1


n,s,k=list(map(int,input().split()))
arr1=list(map(int,input().split()))
arr2=[c for c in input()] 
print(main(arr1,arr2,s,k))