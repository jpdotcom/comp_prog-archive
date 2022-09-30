import sys
import math

def win(arr):
    arr.sort(reverse=True)
    total=sum(arr)
    start1=arr[0]
    start2=0
    
    for i in range(3,len(arr),2):
        start1+=arr[i]
        
    
    start2=total-start1
    
    if start1<start2:
        
        return "second"
    
    elif start1>start2:
        return "first"
        
    return "draw"
    

for _ in range(int(input())):

    n=input()
    arr=list(map(int,input().split()))
    print(win(arr))

