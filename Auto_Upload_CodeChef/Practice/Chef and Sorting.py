import sys
import math
import heapq
def main(arr):
    
    arr_cop=arr.copy()
    heapq.heapify(arr)
    inversions=0
    for e in arr_cop:
        
        if e==arr[0]:
            heapq.heappop(arr)
        else:
            
            inversions+=1 
    
    
    print(inversions)
    return

t=int(input())

for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    (main(arr))        
        