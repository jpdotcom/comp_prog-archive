import sys
import math

def main(arr):



    i=len(arr)-1
    removed=0
    while i!=-1:
        
        if arr[i]==1:
            arr[i]=0
            if i!=0:
                arr[i-1]=arr[i-1]^1
            
            removed=len(arr)-i
        i-=1 
    if removed!=len(arr):
        print("LOSE")

    else:
        print("WIN")
    return 

for _ in range(int(input())):
    arr=list(map(int,input()))
    (main(arr))