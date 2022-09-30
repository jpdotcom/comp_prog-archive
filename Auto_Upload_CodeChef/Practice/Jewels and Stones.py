import sys
import math

def main(arr1,arr2):
    
    
    d={}
    for i in range(len(arr1)):
        
        e=arr1[i]
        
        if e not in d:
            d[e]=0
        d[e]+=1 
    arr2=list(set(arr2))
    
    ans=0
    for e in arr2:
        if e in d:
            ans+=d[e]
    return ans


for _ in range(int(input())):
    
    s=input()
    t=input()
    print(main(t,s))
        