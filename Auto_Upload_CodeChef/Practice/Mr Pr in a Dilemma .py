import sys
import math

def main(a,b,c,d):
    
    if a==b:
        return "YES"
    elif c==d:
        return "NO"
   
    ans=(a-b)/(c-d)
    
    
    if ans ==int(ans):
        return 'YES'
    return "NO"

for _ in range(int(input())):
    
    a,b,c,d=list(map(int,input().split()))
    
    print(main(a,b,c,d))