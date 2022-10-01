import sys
import math

def main(arr):
    
    odds=0
    
    for i in range(len(arr)):
        if arr[i]&1:
            
            odds+=1
    
    ans=0      
    for e in arr:
        if e&1:
            odds-=1 
        else:
            ans+=odds
    return ans

for i in range(int(input())):
    
    n=int(input())
    arr=list(map(int,input().split()))
    print(main(arr))