import sys
import math
import heapq
def half(n):
    return n//2
def main(arr,m):
    a,b,c=arr
    
    while m!=0:
        
        
        
        s=max(a,b,c)
        
        if s==a:
            a=half(a)
        elif s==b:
            b=half(b)
        else:
            c=half(c)
        m-=1
    return max(a,b,c)
            
    
    
    
    

for i in range(int(input())):
    r,g,b,m=list(map(int,input().split()))
    arr=[]
    for j in range(3):
        c=max(list(map(int,input().split())))
        arr.append(c)
    
    print(main(arr,m))
        