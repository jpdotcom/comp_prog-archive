import sys
import math

def main(A,B,C):
    
    
    
    a=A+C 
    b=2*B 
    
    dist=abs(a-b)
    
    return math.ceil(dist/2)

t=int(input())

for i in range(t):
    
    A,B,C=list(map(int,input().split()))
    print(main(A,B,C))

        