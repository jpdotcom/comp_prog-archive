import sys
import math
from queue import Queue 
import heapq

def main(a,b):
    
    n1=False
    n2=False 
    for e in a:
        
        if e=="1":
            n2=True 
        else:
            n1=True 
    if (n2==False) or (n1==False):
        print("Unlucky Chef")
        return
    
    
    n1=0 
    n2=0 
    for i in range(len(a)):
        e=a[i]
        if e=="1" and e!=b[i]:
            n1+=1 
        elif e=="0" and e!=b[i]:
            n2+=1 
    print('Lucky Chef') 
    print(max(n1,n2))
    return
            
    
    
   
    

t=int(input())
for i in range(t):
    a=input()
    b=input()
    main(a,b)