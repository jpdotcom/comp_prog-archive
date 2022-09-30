import sys
import math

def main(arr):
    
    arr.sort()
    
    for i in range(len(arr)-1):
        if arr[i]+1!=arr[i+1]:
            return arr[i+1] if i!=0 else arr[i]

t=int(input())

for i in range(t):
    n=int(input())
    arr=list(map(int,input().split())) 
    print(main(arr))
