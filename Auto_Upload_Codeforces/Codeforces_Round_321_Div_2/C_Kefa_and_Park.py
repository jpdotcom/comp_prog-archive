import math
import random 
from queue import Queue
import time 



def main(n,edges,cats,m):


  adj={} 

  for a,b in edges:
    if a not in adj:
      adj[a]=[] 
    if b not in adj:
      adj[b]=[] 
    adj[a].append(b),adj[b].append(a) 
  
  q=Queue(maxsize=0)

  q.put((1,0,0))
  ans=0
  seen=[False]*(n+1)
  
  while q.qsize()!=0:
    
    v,max_cats,curr_cats=q.get() 
    curr_cats=curr_cats+1 if cats[v-1] else 0
    max_cats=max(max_cats,curr_cats)
    seen[v]=True
    
     
    if len(adj[v])==1 and seen[adj[v][0]]:
      
      if max_cats<=m:
        
        ans+=1 
    elif curr_cats<=m:
      for u in adj[v]:
        if not seen[u]:
          
          q.put((u,max_cats,curr_cats))
  return ans 

n,m=list(map(int,input().split()))
cats=list(map(int,input().split()))
edges=[]
for i in range(n-1):
  edges.append(list(map(int,input().split())))

print(main(n,edges,cats,m)