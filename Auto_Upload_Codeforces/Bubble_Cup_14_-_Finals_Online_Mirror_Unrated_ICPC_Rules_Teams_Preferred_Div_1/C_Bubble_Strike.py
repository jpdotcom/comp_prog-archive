import math
import random
import sys

def main(n,p):
    tot=0 

    for i in range(0,n):
        c0=math.comb(i,3) 
        c1=math.comb(i,2)*math.comb(n-i,1) 
        c2=math.comb(i,1)*math.comb(n-i,2) 
        c3=math.comb(n-i,3) 
        num=c0+c1+0.5*c2+0*c3
        den=c0+c1+c2+c3

        if (num/den)>=p:
            return i
     
    return "WHAT" 

n,p=list(map(float,input().split()))
n=int(n) 
print(main(n,p))
        