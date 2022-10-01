import sys
import math

def main(x,y,stones):
    
    
    a,b,c=stones
    
    for i in range(3):
        for j in range(3):
            if i!=j:
                if a+b+c==x+y and x-stones[i]>=0 and y-stones[j]>=0:
                    return "YES"
    return "NO"

    
    
for _ in range(int(input())):
    
    a,b,c,x,y=list(map(int,input().split()))
    stones=[a,b,c]
    print(main(x,y,stones))