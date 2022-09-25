import math
def LCM(a,b):

  return int(a*b/(math.gcd(a,b)))
def dfs(v,seen,adj):

  seen.add(v) 
  rep=None
  for u in adj[v]:
    if u in seen:
      return u 
    else:
      rep=dfs(u,seen,adj)
  return rep

def main(edges):

  n=len(edges)
  adj={}

  for i in range(len(edges)):

    a=i+1
    b=edges[i] 

    if a not in adj:
      adj[a]=[] 
    if b not in adj:
      adj[b]=[] 
    adj[a].append(b) 
  cycle_len=[] 
  
  p_c=set()
  for i in range(1,n+1): 
    if i not in p_c:
      
      seen=set()
      start=i 
      r=dfs(start,seen,adj)
      
      if r!=start:
        return -1 
      else:
        if len(seen)%2:
          cycle_len.append(len(seen))
        else:
          cycle_len.append(len(seen)//2)
        for e in seen:
          p_c.add(e)
 
  
  ans=1 
  
  for e in cycle_len:
    ans=LCM(ans,e) 
  return ans 

n=int(input())
arr=list(map(int,input().split()))
print(main(arr))
  
  

  


