import sys
import math

def main(arr):
    
    
    
    s=max(arr)
    best_dish=None
    ans=-float('inf')
    for i in range(1,s+1):
        
        temp_ans=0
        last_idx=-float('inf')
        for j in range(len(arr)):
            
            
            if arr[j]==i and last_idx!=j-1:
                temp_ans+=1 
                last_idx=j 
        if temp_ans>ans:
            best_dish=i 
            ans=temp_ans
    return best_dish 


for _ in range(int(input())):
    
    n=int(input())
    arr=list(map(int,input().split()))
    print(main(arr))
            
            
            
            
            

        