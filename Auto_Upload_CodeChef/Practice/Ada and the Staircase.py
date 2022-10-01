import sys
import math

def main(arr,k):
    
    arr=[0]+arr
    ans=0
    for i in range(len(arr)-1):
        
            
            
        ans+=math.ceil((arr[i+1]-arr[i])/k)-1
    return ans 

for i in range(int(input())):
    
    n,k=list(map(int,input().split()))
    
    arr=list(map(int,input().split()))
    
    print(main(arr,k))

        