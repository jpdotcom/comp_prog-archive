import sys
import math

def main(n):
    
    ans=1
    for i in range(1,n):
        ans+=(n/(n-i))
    return ans 


t=int(input())

for i in range(t):
    print(main(int(input())))

        