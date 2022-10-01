import sys
import math

def main(arr):
    odd,even=0,0 
    
    ans=0
    
    for e in arr:
        if e&1:
            odd+=1 
        else:
            even+=1  
    
    for e in arr:
        
        if e&1:
            ans+=even
            odd-=1 
        else:
            ans+=odd
            even-=1  
    return ans

for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    print(main(arr))