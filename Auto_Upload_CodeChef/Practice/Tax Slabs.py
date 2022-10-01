import sys
import math
tax=[[0,250000,0],[250001,500000,5],[500001,750000,10],[750001,1000000,15],[1000001,1250000,20],[1250001,1500000,25],[1500001,float('inf'),30]]

def main(n):
    
    total_tax=0
    for e in tax:
        a,b,c=e 
        if b>n:
            b=n
        if a<=n:
            
            total_tax+=(b-a+1)*c/100 
    return int(n-total_tax)

for _ in range(int(input())):
    print(main(int(input())))

        