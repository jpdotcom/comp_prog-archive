import sys
import math
from queue import Queue 
import heapq

def main(arr):
    
    n=len(arr)
    if n&1:
        print("NO")
        return
    for i in range(len(arr)):
        opposite=(i+n//2)%n 
        if arr[opposite]==-1 and arr[i]==-1:
            arr[opposite]=arr[i]=1 
        elif arr[opposite]==-1:
            arr[opposite]=arr[i]
        elif arr[i]==-1:
            arr[i]=arr[opposite]
        if arr[i]!=arr[opposite]:
            print("NO")
            return
    
    print("YES")
    print(*arr)
    return
    

t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    main(arr)