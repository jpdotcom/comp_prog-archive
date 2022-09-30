import sys
import math

def main(arr,home,n,m):
    
    
    start=[0,0]
    for e in arr:
    
        if e=="L":
            start[0]-=1 
        if e=="R":
            start[0]+=1 
        if e=="D":
            start[1]-=1 
        if e=="U":
            start[1]+=1 
    
    if start==home:
        return "REACHED"
    if start[0]>m or start[0]<0 or start[1]>n or start[1]<0:
        return "DANGER"
    return "SOMEWHERE"

for i in range(int(input())):
    
    m,n=list(map(int,input().split()))
    home=list(map(int,input().split()))
    s=input()
    arr=list(input())
    print("Case",str(i+1)+":",main(arr,home,n,m))