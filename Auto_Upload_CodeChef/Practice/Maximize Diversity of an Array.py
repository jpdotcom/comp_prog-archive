import sys
import math
import heapq
def main(arr,k):
    
    n=len(arr)
    
    if k>=n:
        return n*(n-1)//2
        
    total_unique=n*(n-1)//2
    freq={}
    for e in arr:
        if e not in freq:
            freq[e]=0
        freq[e]+=1 
    
    for e in freq:
        a=freq[e]
        total_unique-=(a*(a-1)//2)
   
    freq_list=[]
    
    for e in freq:
        freq_list.append(-1*freq[e])
        
    heapq.heapify(freq_list)
    
    while k!=0:
        b=-1*heapq.heappop(freq_list)
        
        b-=1 
        total_unique+=b  
        heapq.heappush(freq_list,-1*b)
        k-=1 
    return total_unique 


for _ in range(int(input())):
    n,k=input().split()
    
    n,k=int(n),int(k)
    
    arr=list(map(int,input().split()))
    print(main(arr,k))
        
    
    
    
    

        