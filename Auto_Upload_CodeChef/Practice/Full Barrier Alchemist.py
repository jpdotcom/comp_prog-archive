import sys
import math

def main(L,arr,H,duck,jump):
    
    
    
    
    
    
    
    for i in range(len(arr)):
        
        a,b=arr[i]
        
        if a==1:
            if H-duck>b:
                L-=1
        else:
            if jump<b:
                L-=1
        if L==0:
            return i
    return len(arr)
                
                
for _ in range(int(input())):
    
    n,H,duck,jump,L=list(map(int,(input().split())))
    arr=[]
    for j in range(n):
        
        arr.append(list(map(int,(input().split()))))
    
    print(main(L,arr,H,duck,jump))
        
        
    

        