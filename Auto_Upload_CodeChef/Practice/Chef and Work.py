import sys
import math



def boxes(k,arr):
    res=0
    weight=0
    i=0
    while i!=len(arr):
        
        if arr[i]>k:
            return -1
        if weight+arr[i]<=k:
            weight+=arr[i]
            i+=1
        else:
            res+=1 
            weight=0
    if weight!=0:
        res+=1
    return res
for _ in range(int(input())):
    
    n,k=input().split()
    
    k=int(k)
    
    arr=list(map(int,input().split()))
    print(boxes(k,arr))