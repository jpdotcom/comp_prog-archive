import sys
import math

def main(n):
    
    
    a=(n-1)/4
   
    if a==int(a):
        return "ALICE"
    return "BOB"

for _ in range(int(input())):
    
    n=int(input())
    print(main(n))
        