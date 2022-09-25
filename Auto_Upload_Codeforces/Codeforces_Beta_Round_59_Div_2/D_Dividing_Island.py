import math
import heapq 
import queue

def isvalid(i,j,a,b,c,d):
    
    if j>=a:
        if i>=d:
            return False 
        return True 
    else:
        if i>=b:
            return False 
        return True
            
def main(a,b,c,d,party):
    
    
    
    iters=[[0,a+c,1],[a+c-1,-1,-1]]
    if b>=d:
        start=0 
        if (d+1)%2==0:
            start=1 
    else:
        start=1 
        if (b+1)%2==0:
            start=0
        

    arr=[[0 for i in range(a+c)] for j in range(max(b,d))]
    curr=0
    o=97
    for i in range((max(b,d))):
        x,y,z=iters[start]
        for j in range(x,y,z):
            
            if isvalid(i,j,a,b,c,d):
                arr[i][j]=chr(o)
                party[curr]-=1 
                if party[curr]==0:
                    curr+=1
                    o+=1
            else:
                arr[i][j]="."
        start^=1
           
            
           
    print("YES")        
    for e in arr:
        
        print("".join(e))
    return 

a,b,c,d,n=list(map(int,input().split()))
party=list(map(int,input().split()))
main(a,b,c,d,party)

        
        
            
            
        
        
       
               
       


    
       