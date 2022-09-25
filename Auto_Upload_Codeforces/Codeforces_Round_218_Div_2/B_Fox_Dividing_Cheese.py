import math
import random 
from queue import Queue
import time 
cache={}
def main(a,b):
    
    val=[1,2,3,5]
    if a==b:
        return 0
    elif (a,b) in cache:
        return cache[(a,b)]

    else:
        ans=float('inf')
        for d1 in val:
            for d2 in val:
                if (d1==1 and d2==1):
                    continue 
                else:
                    val1=a/d1 
                    val2=b/d2
                    inc=2 if (d1!=1 and d2!=1) else 1 
                    if val1==int(val1) and val2==int(val2):
                        ans=min(ans,inc+main(val1,val2))
        cache[(a,b)]=ans 
        cache[(b,a)]=ans
        return ans



a,b=list(map(int,input().split()))
res=main(a,b)
if res==float('inf'):
    print(-1)
else:
    print(res)

