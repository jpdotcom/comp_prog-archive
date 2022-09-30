import sys
import math

def main(arr):
    
    
    freq_1={}
    res=(None,-float('inf'))
    freq_2={}
    
    for e in arr:
        if e not in freq_1:
            freq_1[e]=0
        freq_1[e]+=1  
    
    for key in freq_1:
        
        if freq_1[key] not in freq_2:
            freq_2[freq_1[key]]=0
        freq_2[freq_1[key]]+=1
    
    for key in freq_2:
        
        if (freq_2[key]>res[1]) or (freq_2[key]==res[1] and key<res[0]):
            
            res=(key,freq_2[key])
    return res[0]

for _ in range(int(input())):
    n=input()
    arr=list(map(int,input().split()))
    print(main(arr))        