import sys
import math


def main(L,R):
    
    
    
    num_odd=(R-L)//2+1
    num_even=R-L+1-num_odd 
    
    if L%2==0 :
        num_even,num_odd=num_odd,num_even
   
        
    if num_odd%2==1:
        return "Odd"
    return "Even"

for _ in range(int(input())):
    L,R=input().split()
    print(main(int(L),int(R)))