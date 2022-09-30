import sys
import math

def main(arr):
    
    
    freq={}
    for e in arr:
        if e not in freq:
            freq[e]=0
        freq[e]+=1 
    
    for e in arr:
        freq[e]-=1 
        
        if freq[e]:
            return "Yes"
    
    return "No"
    
for i in range(int(input())):
    
    n=input()
    arr=list(map(int,input().split()))
    print(main(arr))

        