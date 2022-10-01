import sys
import math

def main(arr1,arr2):
    
    
    
    s=sum(arr1)+sum(arr2)
    a,b=0,0
    for i in range(len(arr1)):
        if arr1[i]&1:
            a+=1 
    
        if arr2[i]&1:
            b+=1 
    
    s-=abs(a-b)
    
    print(s//2)
    

for _ in range(int(input())):
    
    n=int(input())
    
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))
    (main(arr1,arr2))
        