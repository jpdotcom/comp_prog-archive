import sys
import math

def main(arr,k):
    
    
    arr.sort(reverse=True)
    low=arr[k-1]
    ans=k
    for i in range(k,len(arr)):
        if arr[i]==low:
            ans+=1 
        else:
            return ans 
    return ans 
    
for i in range(int(input())):
    n,k=input().split()
    arr=list(map(int,input().split()))
    print(main(arr,int(k)))
        
    
    
    

        