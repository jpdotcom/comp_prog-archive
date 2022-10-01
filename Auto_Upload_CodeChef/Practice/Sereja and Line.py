import sys
import math

def main(arr):
    
    
    ans=0
    line=[None]*len(arr)
    
    line[0]=1 
    
    for i in range(1,len(arr)):
        
        e=i+1 
        next_to=arr[i]
        idx=-1
        if next_to!=0:
            
            for j in range(len(line)):
                if next_to==line[j]:
                    idx=j
        left=0
        right=0 
        for j in range(0,idx+1):
            if line[j]:
                left+=1 
        for j in range(idx+1,len(line)):
            if line[j]:
                right+=1 
        ans+=min(right,left)
    
        line=line[0:idx+1]+[e]+line[idx+1:]
        
    
    
    return ans
                    

for _ in range(int(input())):
    n=int(input())
    
    arr=list(map(int,input().split()))
    print(main(arr))
        
        

        