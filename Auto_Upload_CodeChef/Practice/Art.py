import sys
import math

def main(arr):
    
    
    for i in range(1,len(arr)-1):
        if arr[i]==arr[i-1] and arr[i]==arr[i+1]:
            return "Yes"
    return "No"


for _ in range(int(input())):
    b=int(input())
    arr=list(map(int,input().split()))
    print(main(arr))

        