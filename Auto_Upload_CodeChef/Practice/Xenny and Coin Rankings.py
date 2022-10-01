import sys
import math

def main(U,V):
    
    
    n=U+V
    return (n*(n+1))//2+U+1
    
    
t=int(input())
    
for i in range(t):
    
    U,V=list(map(int,input().split()))
    print(main(U,V))
        