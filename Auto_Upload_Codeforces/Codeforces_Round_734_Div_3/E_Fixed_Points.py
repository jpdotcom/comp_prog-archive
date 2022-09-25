import math
import random
import sys
def main(arr,k):


    dp=[[-float('inf') for i in range(len(arr)+1)] for j in range(len(arr)+1)]
    dp[0][0]=0;
    
    for i in range(1,len(arr)+1):
        for j in range(0,i+1):
            val=1 if arr[i-1]==i-j else 0
            dp[i][j]=max(dp[i-1][j-1],val+dp[i-1][j])
    ans=-1 
    for i in range(len(arr),-1,-1):
        if dp[-1][i]>=k:
            ans=i 
    return ans
        

        
t=int(input())
out=[] 
for i in range(t):
    n,k=list(map(int,input().split())) 
    arr=list(map(int,input().split()))
    out.append(main(arr,k)) 
for e in out:
    print(e) 

                






            
    
            
            

        


                    
                    

            
            