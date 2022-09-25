
import math 
import sys
from decimal import Decimal
sys.setrecursionlimit(3000)
adj={}
n=int(input())
roots=[]
for i in range(n):
  a=i+1
  b=int(input())
  if b==-1:
    if a not in adj:
      adj[a]=[] 
    roots.append(a)
  else:
    if a not in adj:
      adj[a]=[] 
    if b not in adj:
      adj[b]=[] 
    adj[b].append(a)

def dfs(u,p):

  ans=1

  for v in adj[u]:
    if v!=p:
      ans=max(ans,1+dfs(v,u))
  return ans

ans=0

for e in roots:
  ans=max(ans,dfs(e,0))
print(ans)
  
    






  
  
