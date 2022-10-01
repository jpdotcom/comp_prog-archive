import sys
import math

def main(n):
    
    
    a=1 
    b=0
    c=0
    
    
    for i in range(1,n):
        
        
        if i%26==10:
            c+=b 
            b=0
        if i%26==0: 
            a+=2*c
            c=0 
        if i%26==2:
            
            b+=a 
            a=0
    print(a,b,c)
    return 

for i in range(int(input())):
    
    n=int(input())
    main(n)
        