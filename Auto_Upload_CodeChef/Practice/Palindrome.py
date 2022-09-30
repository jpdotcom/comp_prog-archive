import sys
import math
from queue import Queue 
import heapq
def powermod(a, b, n):
    
    if b==0:
        return 1%n
    if b == 1:
        return a % n
    r = powermod(a, b // 2, n)
    r = r * r % n
    if (b & 1) == 1: 
        r = r * a % n
    return r
def main(n):
    exp=None
    mult=0
    mod=10**9+7
    if n&1==1:
        exp=(n-1)//2
        s=powermod(26,(n+1)//2,mod)
        mult=int(s)
    else:
        exp=n//2 
    a=(52*powermod(25,1000000005,mod))%mod
    b=(powermod(26,exp,mod)-1)%mod
    c=mult 
    
    return ((a*b)%mod+c%mod)%mod

t=int(input())
for i in range(t):
    n=int(input())
    print(main(n))