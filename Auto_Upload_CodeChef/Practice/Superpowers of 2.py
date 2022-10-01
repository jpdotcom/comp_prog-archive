import sys
import math
from queue import Queue 
import heapq


def powermod(a, b, n):
    if b == 1:
        return a % n
    r = powermod(a, b // 2, n)
    r = r * r % n
    if (b & 1) == 1: 
        r = r * a % n
    return r

def main(n):
    print(powermod(2,2*int(bin(n)[2:]),10**9+7))
    
    
    

t=int(input())
for i in range(t):
    n=int(input())
    main(n)