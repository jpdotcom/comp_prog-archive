import sys
import math

def main(arr):
    r_bound=float('inf')
    l_bound=-float('inf')
    
    
    for i in range(1,len(arr)):
        e=arr[i]
        if l_bound<e and e<r_bound: 
            if arr[i]<arr[i-1]:
                r_bound=arr[i-1]
            else:
                l_bound=arr[i-1]
        else:
            return "NO"
    return 'YES'
            
t=int(input())


for i in range(t):
    n,R=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    print(main(arr))