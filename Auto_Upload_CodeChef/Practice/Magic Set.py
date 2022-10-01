import sys
import math

def main(arr,m):
    
    ans=0
    for e in arr:
        if e%m==0:
            ans+=1 
    return 2**ans-1 


for i in range(int(input())):
    
    n,m=list(map(int,input().split()))
    
    arr=list(map(int,input().split()))
    
    print(main(arr,m))

        