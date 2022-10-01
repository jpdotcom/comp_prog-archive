import sys
import math

def main(arr,m,k,l,r):
    
    ans=float('inf')
    for e in arr:
        temp,price=e
        after_walk=None
        if temp<=k:
            
            if temp+m>k:
                after_walk=k 
            else:
                after_walk=temp+m 
        else:
            if temp-m<k:
                after_walk=k 
            else:
                after_walk=temp-m
        if l<=after_walk and after_walk<=r:
            ans=min(ans,price)
    return ans if ans!=float('inf') else -1
        
                
for _ in range(int(input())):
    n,m,k,l,r=list(map(int,input().split()))
    arr=[]
    for i in range(n):
        arr.append(list(map(int,input().split())))
    print(main(arr,m,k,l,r))
        