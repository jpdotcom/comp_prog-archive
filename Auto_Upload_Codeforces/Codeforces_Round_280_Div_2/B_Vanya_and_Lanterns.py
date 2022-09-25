import math
import random 

def main(arr,l):
    arr.sort() 
 
    ans=-float('inf')
    for i in range(len(arr)-1):

        
        
        ans=max(ans,(arr[i+1]-arr[i])/2) 
    ans=max(ans,l-arr[-1])
    ans=max(ans,arr[0])
    return ans 
            
        
n,l=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,l)