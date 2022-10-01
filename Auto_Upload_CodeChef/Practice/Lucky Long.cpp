import sys
import math




for _ in range(int(input())):
    ans=0
    n=input().strip()
    for e in n:
        if e!="4" and e!="7":
            ans+=1
    
    print(ans)
        