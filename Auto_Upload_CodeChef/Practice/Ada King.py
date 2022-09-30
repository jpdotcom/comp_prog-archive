import sys
import math

def getK(K):
    ans=[["X" for i in range(8)] for j in range(8)]
    
    pos=set()
    start=None
    i=0
    j=0
    while K!=0:
        start=(i,j)
        pos.add(start)
       
        
        if j==7:
            i+=1 
            j=0
        
        else:
            j+=1 
        
        K-=1
    
    for i in range(len(ans)):
        for j in range(len(ans[0])):
            
            if (i,j) in pos:
                ans[i][j]="." if (i,j)!=(0,0) else "O"
    
    
    return ans    

for _ in range(int(input())):
    
   
    k=int(input())
    res=getK(k)
    
    for e in res:
        x="".join(e)
        print(x)
    
           
        
        
        

        