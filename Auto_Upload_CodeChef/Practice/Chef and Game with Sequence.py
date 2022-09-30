import sys
import math

def main(arr):
    
    
    
    s={0:0,1:0}
    
    
    for e in arr:
        if e&1:
            s[1]+=1 
        else :
            s[0]+=1 
    
    if s[1]>1:
        if s[1]%2==0:
            s[0]+=1 
            s[1]=0 
        else:
            s[0]+=1 
            s[1]=1 
    if s[0]>0:
        return 1+s[1]
    return s[1]
for _ in range(int(input())):
    n=int(input())
    arr=map(int,input().split())
    print(main(arr))

        