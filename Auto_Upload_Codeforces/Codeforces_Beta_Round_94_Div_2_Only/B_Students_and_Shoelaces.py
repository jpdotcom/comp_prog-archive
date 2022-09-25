import math

def main(n,edges):

    adj={}

    for e in edges:
        x,y=e
        if x not in adj:
            adj[x]=[]
        if y not in adj:
            adj[y]=[]
        adj[y].append(x)
        adj[x].append(y)

    
    ans=0
    while True:
        found=False
        remove=[]
        for e in adj:
            if len(adj[e])==1:
                remove.append(e)
                found=True 
        
        for e in remove:
            
            
            if len(adj[e])!=0:
                v=adj[e].pop()
                adj[v].remove(e)

        if found:
            ans+=1 
        else:
            return ans
    
n,m=list(map(int,input().split()))
edges=[]
for i in range(m):
    edges.append(list(map(int,input().split())))
print(main(n,edges))

    


