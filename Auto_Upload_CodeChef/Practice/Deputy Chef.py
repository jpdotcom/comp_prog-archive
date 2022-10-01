import sys
import math

def main(arr1,arr2,n):
    
    
    ans=-1
    for i in range(len(arr2)):
        
        
        curr_solider=arr2[i]
        
        
        prev_soldier=arr1[(i-1)%n]
        next_solider=arr1[(i+1)%n]
        
        if prev_soldier+next_solider<curr_solider:
            ans=max(curr_solider,ans)
    return ans

for _  in range(int(input())):
    
    n=int(input())
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))
    print(main(arr1,arr2,n))
        