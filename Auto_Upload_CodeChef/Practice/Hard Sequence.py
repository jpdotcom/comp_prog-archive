import sys
import math

def main(n):
    
    last_idx={0:0}
    
    freq={0:1} 
    
    curr_number=0
    
    for i in range(1,n):
        
        
        diff=i-1-last_idx[curr_number]
        
        if diff not in freq:
            freq[diff]=0 
            last_idx[diff]=i
        freq[diff]+=1
        last_idx[curr_number]=i-1 
        curr_number=diff
        
    return freq[curr_number]
for i in range(int(input())):
    
    print(main(int(input())))
            
    
    
    

        