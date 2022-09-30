import sys
import math

def main(arr):
    
    
    arr_set=set(arr)
    if 0 in arr_set:
        return len(arr_set)-1 
    return len(arr_set)

for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    
    print(main(arr))
    

        