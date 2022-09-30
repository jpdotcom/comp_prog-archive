import sys
import math
import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom  # or / in Python 2
def sub(arr,k):
    
    
    s_arr=sorted(arr)
    n=0
    b=0
    for i in range(k):
        e=s_arr[i]
        if e==s_arr[k-1]:
            b+=1
    for i in range(len(arr)):
        if arr[i]==s_arr[k-1]:
            n+=1
        
    return int(math.factorial(n)/(math.factorial(n-b)*math.factorial(b)))
for _ in range(int(input())):
    
    n,k=input().split()
    k=int(k)
    
    arr=list(map(int,input().split()))
    print(sub(arr,k))
    
        