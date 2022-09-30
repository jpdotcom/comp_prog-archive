import sys
import math

def main(n):
    
    if n==0:
        return 1 
    return n*main(n-1)
    

for _ in range(int(input())):
    print(main(int(input())))

        