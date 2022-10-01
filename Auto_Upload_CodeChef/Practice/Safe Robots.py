import sys
import math

def main(arr,n,m):
    
    
    a=None 
    b=None 
    
    
    for i in range(len(arr)):
        e=arr[i]
        if e=="A":
            a=i 
        elif e=="B":
            b=i 
    ans=(b-a)/(n+m)
    
    if ans==int(ans) :
        return "unsafe"
    return "safe"
    
for _ in range(int(input())):
    
    
    arr=list(input())
    
    n,m=input().split()
    n,m=int(n),int(m)
    
    print(main(arr,n,m))

        