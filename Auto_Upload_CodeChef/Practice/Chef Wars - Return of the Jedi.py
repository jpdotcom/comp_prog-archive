import sys
import math

def attack(p,h):
    
    
    while p!=0:
        h-=p
        p=math.floor(p/2)
        
    if h<=0:
        return 1 
    
    return 0

        
        
for _ in range(int(input())):
    
   
    h,p=input().split()
    h=int(h)
    p=int(p)
    print(attack(p,h))