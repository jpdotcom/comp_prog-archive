import sys
import math

def main(n):

    arr=[]
    for i in range(1,n+1):
        arr.append(i)
    i=0 
    j=1 
    
    while i<n and j<n:
        arr[i],arr[j]=arr[j],arr[i]
        i+=2
        j+=2 
    
    if n&1:
        arr[-2],arr[-1]=arr[-1],arr[-2]
    print(*arr)
    return 
for _ in range(int(input())):
    n=int(input())
    main(n)

    
        

        