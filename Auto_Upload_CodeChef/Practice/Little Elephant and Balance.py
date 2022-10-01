import sys
import math

def main(arr):
    
    
    n=len(arr)
    ans=n*(n+1)/2
    a=0
    for i in range(len(arr)):
        
        if arr[i]=="7":
            a+=1
        else:
            
            ans-=(a*(a+1))/2 
           
            a=0 
    ans-=(a*(a+1)/2)
    return int(ans)


for _ in range(int(input())):
    arr=list(input())
    print(main(arr))
            

        