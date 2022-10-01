import sys
import math

def main(arr):
    
    
    start=arr[0]
    
    for i in range(1,len(arr)):
        
        for j in range(len(start)):
            a=int(start[j])
            b=int(arr[i][j])
            
            if a and b:
                start[j]="0"
            elif a or b:
                start[j]="1"
            else:
                start[j]="0"
        
    ans=0
    for e in start:
        if e=="1":
            ans+=1

    return ans
for _ in range(int(input())):
    n=int(input())
    arr=[]
    for i in range(n):
        arr.append(list(input()))
    print(main(arr))