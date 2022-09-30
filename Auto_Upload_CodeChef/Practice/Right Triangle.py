import sys
import math

def main(h,s):
    
    
    check=h**4-16*s**2
    ans=[None,None,h]
    if check>=0:
        
        temp=(h**2+math.sqrt(check))/2 
        
        if temp>0:
            a=math.sqrt(temp)
            b=math.sqrt(h**2-a**2)
            ans[0]=a 
            ans[1]=b
            ans.sort()
            print(*ans)
            return 
    print(-1)
    return
    
t=int(input())

for i in range(t):
    h,s=list(map(int,input().split()))
    main(h,s)
    
        
        
        
    
    
    
    

        