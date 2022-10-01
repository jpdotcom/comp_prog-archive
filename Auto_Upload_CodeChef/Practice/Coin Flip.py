import sys
import math

def main(I,N,Q):
    
    not_i=N//2 if N%2==0 else N//2+1 
    
    if I==Q:
        return  N-not_i
    return not_i
    


        
t=int(input())

for i in range(t):
    
    g=int(input())
    
    for j in range(g):
        
        I,N,Q=list(map(int,input().split()))
        print(main(I,N, Q))
