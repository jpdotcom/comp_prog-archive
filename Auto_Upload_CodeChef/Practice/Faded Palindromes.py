import sys
import math

def main(arr):


    n=len(arr)-1 
    
    for i in range(len(arr)//2):
        
        a=arr[i]
        b=arr[n-i]
        if a!=b and a!="." and b!=".":
            return "-1"
        if a=="." and b==".":
            
            arr[i]="a"
            arr[n-i]="a"
        
        else:
            
            if a!=".":
                arr[n-i]=a 
            elif b!=".":
                arr[i]=b
        
    if arr[len(arr)//2]==".":
        arr[len(arr)//2]="a"
    return "".join(arr)

for _ in range(int(input())):
    arr=list(input())
    print(main(arr))
    