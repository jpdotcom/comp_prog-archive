import sys
import math

def main(a,b):
    
    
    
    for i in range(0,len(a)-2):
        
     
        change=b[i]-a[i]
        
        
        if change<0:
            return 'NIE'
            
            
        else:
            a[i]+=change 
            a[i+1]+=2*change 
            a[i+2]+=3*change
    return "TAK" if a==b else 'NIE'
    
t=int(input())
for i in range(t):
    n=int(input())

    a=list(map(int,input().split()))
    
    b=list(map(int,input().split()))
    
    print(main(a,b))
    
    
    

        