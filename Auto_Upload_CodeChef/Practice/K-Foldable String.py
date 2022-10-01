import sys
import math

def main(arr,K,N):
    
    freq={} 
    freq[0]=0
    freq[1]=0
    for e in arr:
        b=int(e)
        
        freq[b]+=1 
    ans=None
    for i in range(K+1):
        
        if i*N/K == freq[0]:
            if (K-i)*(N/K)==freq[1]:
                ans=i 
              
    if ans==None:
        return "IMPOSSIBLE"
    s=["0" for i in range(ans)]+["1" for i in range(K-ans)] 
    ans=[]
    for j in range(int(N/K)):
        ans+=s 
        s.reverse() 
    return "".join(ans) 

t=int(input())
for i in range(t):
    N,K=list(map(int,input().split()))
    
    arr=input()
    print(main(arr,K,N))
        
                

        