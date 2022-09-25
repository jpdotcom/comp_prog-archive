import math
import heapq 
import queue


def main(arr):
    
    dist={}
    for i in range(len(arr)):
        
        if arr[i] not in dist:
            dist[arr[i]]=[] 
        dist[arr[i]].append(i+1)
    if 0 not in dist or len(dist[0])>1:
        print(-1)
        return
    end=max(arr)+1 
    edges=[]
    for i in range(1,end):
        if i in dist:
            if (i-1) not in dist:
                print(-1)
                return
            
            nodes=dist[i] 
            prev_len=len(dist[i-1])
            s=0 
            
            for j in range(len(nodes)):
                edges.append([nodes[j],dist[i-1][s]])
                
                s=(s+1)%prev_len
    
    adj={}
    for a,b in edges:
        if a not in adj:
            adj[a]=[]
        if b not in adj:
            adj[b]=[] 
        adj[a].append(b),adj[b].append(a)
   
    for a in adj:
        if len(adj[a])>k:
            print(-1)
            return
    print(len(edges))
    for e in edges:
        print(*e)
    return
    
    
                
n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))
main(arr)
            
            
        
        
       
               
       


    
       