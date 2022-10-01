import sys
import math

def bit_and(arr):
    
    
    ans=0
    freq={}
    for e in arr:
        if e not in freq:
            freq[e]=0
        freq[e]+=1 
        
    for e in arr:
        
        freq[e]-=1
        
        for key in freq:
            if key&e==e:
                
                ans+=freq[key]
    return ans


for _ in range(int(input())):
    
    n=input()
    
    arr=list(map(int,input().split()))
    
    print(bit_and(arr))
    

        