import sys
import math

def main(n):
    
    s=n-1
    for i in range(1,int(math.sqrt(n))+1):
        a=n/i
        if a==n//i:
            if abs(i-a)<s:
                s=abs(i-a)
    print(int(s))
            
            
            
t=int(input())
for i in range(t):
    n=int(input())
    main(n)