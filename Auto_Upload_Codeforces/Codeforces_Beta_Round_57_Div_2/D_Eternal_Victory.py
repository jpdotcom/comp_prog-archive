
import math 
import sys
sys.setrecursionlimit(3000)
n=int(input())
adj={}
for i in range(n-1):
  a,b,c=list(map(int,input().split()))
  if a not in adj:
    adj[a]=[] 
  if b not in adj:
    adj[b]=[] 
  adj[a].append((b,c))
  adj[b].append((a,c))
if 1 not in adj:
  adj[1]=[]

visited=[False]*(n+1)
dist=[0]*(n+1)
ans=[-1]*(n+1)
p=[-1]*(n+1)
def dfs(u):
  visited[u]=True 
  
  
  t=0
  
  for v,w in adj[u]:
    if not visited[v]:
    
      p[v]=u
      t+=w 
      t+=dfs(v) 
  dist[u]=t 
  return t
dfs(1)
def solve(u):

  t=float('inf')
  c=False
  for v,w in adj[u]:
    if p[v]==u:
      if ans[v]==-1:
        
        solve(v)
      c=True
      t=min(t,2*dist[u]-2*dist[v]-w+ans[v])
   
  ans[u]=t
  if not c:
    ans[u]=0 
  return ans[u]

solve(1)
print(ans[1])
     
      


  
    
      
     