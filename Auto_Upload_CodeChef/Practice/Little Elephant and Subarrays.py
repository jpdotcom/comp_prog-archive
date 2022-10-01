import sys
import math

def main(arr,k):
    
    ans=0
    for i in range(len(arr)):
        curr_min=float('inf')
        for j in range(i,len(arr)):
            curr_min=min(curr_min,arr[j])
            
            if curr_min==k:
                ans+=1 
    return ans
        

n=int(input())
arr=list(map(int,input().split()))


for i in range(int(input())):
    
    print(main(arr,int(input())))