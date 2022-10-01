import sys
import math

def main(arr):
    return arr[2] if arr[0]!=arr[1] else 1
    
for i in range(int(input())):
    
    arr=list(map(int,input().split()))
    print(main(arr))

        