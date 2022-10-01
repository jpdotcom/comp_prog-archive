import sys
import math

def main(a,b):
    
    
    
    a_sum=0
    b_sum=0
    ans=0
    for i in range(len(a)):
        if a_sum==b_sum and a[i]==b[i]:
            ans+=a[i]
        a_sum+=a[i]
        b_sum+=b[i]
    
    
    
    return ans 


t=int(input())

for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    print(main(a,b))
            

        