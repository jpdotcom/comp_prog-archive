import sys
import math
from queue import Queue 
import heapq


def getprimes(n):
    
    primes=[True]*(n+1)
    
    for i in range(2,int(math.sqrt(n))+1):
        if primes[i]:
            for j in range(i**2,len(primes),i):
                primes[j]=False 
    
    prime_num=[]
    for j in range(2,len(primes)):
        if primes[j]:
            prime_num.append(j)
    return prime_num
        
def main(n,arr):
    adj={}
    
    u=None
    for i in range(1,n+1):
        adj[i]=[]
    for edge in arr:
        x,y=edge 
       
        adj[x].append(y)
        adj[y].append(x)

    primes=getprimes(100)
  
    p1,p2=1,1
   
    
    for e in reversed(primes):
        if p1<=p2:
            p1*=e 
        else:
            p2*=e 
    
    
    ans=[]
    u=1
    q=Queue(maxsize=0)
    q.put((u,p1))
    seen=set([u])
    ans=[0 for i in range(n+1)]
    while q.qsize()!=0:
        
        k,p=q.get()
        
        ans[k]=p
        new_p=p2 if p==p1 else p1
        for v in adj[k]:
            if v not in seen:
                seen.add(v)
                
                q.put((v,new_p))
    print(*ans[1:])
                

t=int(input())
for i in range(t):
    n=int(input())
    arr=[]
    for i in range(n-1):
        arr.append(list(map(int,input().split())))
    main(n,arr)
    