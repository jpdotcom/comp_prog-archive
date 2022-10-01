import sys
import math
from fractions import Fraction
def main(n,a,k):
    
    first_term=n*a
    
    interior=180*(n-2)
    
    summation=(n*(n-1))/2 
    
    diff=(interior-first_term)/summation
    
    ans=a+diff*(k-1)
    
    
    if ans==int(ans):
        print(int(ans),1)
    
    else:
        b=str(Fraction(ans).limit_denominator())
        b=b.split("/")
        print(int(b[0]),int(b[1]))
    

    
    return
for _ in range(int(input())):
    
    
    n,a,k=list(map(int,input().split()))
    main(n,a,k)

        