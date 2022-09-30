import sys
import math

def main(L,K):
    if K>L:
        return 0
    
    valid=L-K+1 
    
    return int(valid*(valid+1)/2)

        

for i in range(int(input())):
    
    L,K=list(map(int,input().split()))
    
    print("Case "+str(i+1)+": "+str(main(L,K)))