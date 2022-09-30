import sys
import math

def main(arr):
    
    
    arr.sort(reverse=True)
    ans=0
    for i in range(0,len(arr),4):
        
        ans+=arr[i]
        if i!=len(arr)-1:
            ans+=arr[i+1]
    return ans 


for _ in range(int(input())):
    n=input()
    print(main(list(map(int,input().split()))))
        

        