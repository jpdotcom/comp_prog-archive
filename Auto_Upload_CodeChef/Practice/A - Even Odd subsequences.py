import sys
import math

def main(arr,k):
    
    
    x=[]
    y=[]
    
    
    
    for e in arr:
        if e%2==0:
            x.append(e)
            y.append(0)
        else:
            x.append(0)
            y.append(e)
            
    a=[0]*n
    b=[0]*n
    a[0]=x[0]
    b[0]=y[0]
    for i in range(1,n):
        
        if i<k:
            a[i]=max(x[i],a[i-1])
            b[i]=max(y[i],b[i-1])
        else:
            a[i]=max(x[i]+a[i-k-1],a[i-1])
            b[i]=max(y[i]+b[i-k-1],b[i-1])
    
    print(a[-1]+b[-1]) 
    return 

for i in range(int(input())):
    n,k=list(map(int,input().split()))
    
    arr=list(map(int,input().split()))
    
    (main(arr,k))

        