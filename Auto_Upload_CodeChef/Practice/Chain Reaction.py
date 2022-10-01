import sys
import math

def main(arr):
    
    
    
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            adj=0
            if i<len(arr)-1:
                adj+=1
            if i>0:
                adj+=1 
            if j<len(arr[0])-1:
                adj+=1 
            if j>0:
                adj+=1 
            if adj<=arr[i][j]:
                return "Unstable"
    return "Stable"


for _ in range(int(input())):
    
    n,m=input().split()
    arr=[]
    n=int(n)
    for i in range(n):
        arr.append(list(map(int,input().split())))
    print(main(arr))

        