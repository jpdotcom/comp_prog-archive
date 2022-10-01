import sys
import math

mod=1000000007

def main(n,k):
    
    if n<=k:
        print(1)
        return
    arr=[1]*k 
    
    next_sum=k 
    i=k-1
    while i!=n-1:
        arr.append(next_sum)
        
        next_sum=(next_sum-arr[i-k+1]+arr[-1])%mod
        
        i+=1 
    
    print(arr[-1])
    return 

n,k=list(map(int,input().split()))
main(n,k)
    

        