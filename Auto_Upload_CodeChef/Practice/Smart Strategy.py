import sys
import math

def main(mult_sum,x):
    
    return math.floor(x/mult_sum)
    
    

for _ in range(int(input())):
    
    n,q=input().split()
    
    arr=list(map(int,input().split()))
    
    
    ans=1
    for e in arr:
        ans*=e
    queries=list(map(int,input().split()))
    res=[]
    for e in queries:
        res.append(main(ans,e))
    print(*res)    
    
    

        