import math

cache={}
max_n=10**18
def get_depth(x):
    return int(math.log2(x))
def LCA(u,v):
    ans=[]
    while u!=v:
        
        d1=get_depth(u)
        d2=get_depth(v)
        if d1>d2:
            u,v=v,u 
        ans.append(v)
        v//=2
    return ans
   

q=int(input())
ans=[]
for i in range(q):
    
    curr=list(map(int,input().split()))
    if curr[0]==1:
        n1,n2,w=curr[1],curr[2],curr[3]
        nodes=LCA(n1,n2)
        for e in nodes:
            if e not in cache:
                cache[e]=0
            cache[e]+=w 
            
    else:
       temp=0
       n1,n2=curr[1],curr[2]
       nodes=LCA(n1,n2)
       for e in nodes:
           if e in cache:
               temp+=cache[e]
           
           
       ans.append(temp)
for e in ans:
    print(e)
       
               
       


    
       