import math
import random

def query(l,r,n,tree):
  
  ans=float('inf')
  idx=None 
  l+=n
  r+=n
  prev_ans=ans
  while l<=r:
    if l&1:
      #MODIFY QUERY HERE
      
      ans=min(tree[l][0],ans)
      
      if (prev_ans!=ans):
          idx=tree[l][1]
          prev_ans=ans 
      l+=1
    if r&1==0:
      #MODIFY QUERY HERE
      ans=min(tree[r][0],ans)
      if (ans!=prev_ans):
          idx=tree[r][1]
          prev_ans=ans
      r-=1
    l>>=1 
    r>>=1
  return idx

def update(i,val,n,tree):
  
  i+=n 
  
  tree[i][0]=val[0]
  tree[i][1]=val[1] 
  i>>=1
  
  while i>=1:
    #MODIFY UPDATE HERE
    tree[i][0]=min(tree[2*i][0],tree[2*i+1][0]) 
    if tree[i][0]==tree[2*i][0]:
        tree[i][1]=tree[2*i][1]
    else:
        tree[i][1]=tree[2*i+1][1]

    i>>=1

def main(arr,back):

    n=len(arr)
    tree=[[float('inf'),None] for i in range(2*n)]

    for i in range(len(arr)):
        vals=[i+back[i]-arr[i+back[i]],i]
        
        update(i,vals,n,tree) 
    
    start=n-1 
    out=[]
    while (start!=-1):
        if start-arr[start]<=-1:
            out.append(0)
            break
        next_val=query(start-arr[start],start,n,tree) 
       
        if (next_val+back[next_val]==start):
            print(-1)
            return
        else: 
            out.append(next_val+1)
            start=next_val+back[next_val]
           
    print(len(out))
    print(*out)
    return 
n=int(input())
arr=list(map(int,input().split()))
back=list(map(int,input().split())) 
main(arr,back)

           