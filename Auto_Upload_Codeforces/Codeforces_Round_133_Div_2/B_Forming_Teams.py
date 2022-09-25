import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
 
n,m=list(map(int,input().split()))
adj={}
seen=set([])
invalid=set([])
cnt=[0,0]
for i in range(m):
  a,b=list(map(int,input().split()))
  if a not in adj:
    adj[a]=[] 
  if b not in adj:
    adj[b]=[]
  adj[a].append(b),adj[b].append(a)
 
c=[-1]*(n+1)
def dfs(v,adj,seen,invalid,cnt):
  global a 
  global b
  seen.add(v)
  for u in adj[v]:
    
    if c[u]==c[v]:
        invalid.add(u)
        cnt[c[u]]-=1
        c[u]=-1 
      
    if u not in seen and u not in invalid:
 
      
     
      c[u]=c[v]^1 
      cnt[c[u]]+=1 
      dfs(u,adj,seen,invalid,cnt)
 
 
for i in range(1,n+1):
  if i not in adj:
    adj[i]=[] 
  if i not in seen and i not in invalid:
    if cnt[0]>cnt[1]:
      c[i]=1 
      cnt[1]+=1
    else:
      c[i]=0
      cnt[0]+=1
    dfs(i,adj,seen,invalid,cnt)

if (n-len(invalid))%2==0:
  print(len(invalid))
else:

  print(len(invalid)+1)

