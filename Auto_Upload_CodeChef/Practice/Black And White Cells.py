import sys
import math

def main(arr):
    
    
    left=0
    right=0
    count=0
    for e in arr:
        if e=="W":
            left=count
            count=0 
        else:
            count+=1 
    right=count 
    
    if left==right:
        return "Chef"
    else:
        return "Aleksa"

for _ in range(int(input())):
    
    a=list(input())
    print(main(a))
        