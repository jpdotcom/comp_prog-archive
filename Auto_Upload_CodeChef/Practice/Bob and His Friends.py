import sys
import math

def main(arr,a,b,c):
    
    ans=float('inf')
    for i in range(len(arr)):
        e=arr[i]
        if abs(b-e)+c+abs(e-a)<ans:
            ans=abs(b-e)+c+abs(e-a)
    return ans



for _ in range(int(input())):
    
    n,a,b,c=list(map(int,input().split()))
    
    arr=list(map(int,input().split()))
    
    print(main(arr,a,b,c))
    
    

        