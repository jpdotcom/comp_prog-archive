import sys
import math

def main(arr):
    
    
    arr.sort(reverse=True)
    
    
    for i in range(1,len(arr)):
        
        arr[i]=0.5*(arr[i]+arr[i-1])
        arr[i-1]=0 
    return arr[-1]


t=int(input())

for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
   
    print(main(arr))
        