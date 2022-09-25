


adj={}

n,m=list(map(int,input().split()))

for i in range(m):
  a,b,color=list(map(int,input().split()))
  if a not in adj:
    adj[a]=[]
  if b not in adj:
    adj[b]=[]
 
  adj[a].append((b,color))
  adj[b].append((a,color))

for i in range(1,n+1):
  if i not in adj:
    adj[i]=[]
q_l=int(input())
q=[]
for i in range(q_l):

  q.append(list(map(int,input().split())))

visited=[0]*(n+1)


def dfs(u,v,color):
 
  global visited
  visited[u]=1
 
  if u==v:
    
    return True 
  
  for k,c in (adj[u]):
    
    if not visited[k] and c==color:
      
      s=dfs(k,v,color)
      
      if s:
        
        return True
 
  return False
  
  




def main(q,n,m):
  
  global visited
  for i in range(len(q)):
    u,v=q[i]
    ans=0

    
    
    for j in range(1,m+1):
   
      visited=[0]*(n+1)
      found=dfs(u,v,j)
      
      if found:
        ans+=1
      
    print(ans)

    
      

    
main(q,n,m