import sys
import math
from fractions import Fraction
def main(n):
    m=0
    if n%2==1:
        m=1
    b=int(n/2)
    
    
    print(1,10**(n-(b+m)))
    return

for _ in range(int(input())):
    
    n=int(input())
    main(n)
    
    

        