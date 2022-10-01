import sys
import math

def main(TS):
    
    
    if TS%2==1:
        print(TS//2) 
    
    else:
        n=0 
        a=TS
        while (a%2)==0:
            a//=2
        
        print(int(a//2))
    return 

for _ in range(int(input())):
    TS=int(input())
    (main(TS))