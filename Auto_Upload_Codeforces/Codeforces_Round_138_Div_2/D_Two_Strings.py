import math
import time
import sys

def query(l,r,n,tree):
  
  ans=0
  l+=n
  r+=n
  while l<=r:
    if l&1:
      ans|=tree[l]
      l+=1
    if r&1==0:
      ans|=tree[r]
      r-=1
    l>>=1 
    r>>=1
  return ans 

def update(i,val,n,tree):
  
  i+=n 
  
  tree[i]+=val 
  i>>=1
  
  while i>=1:
    
    tree[i]=tree[2*i]|tree[2*i+1]
    i>>=1 
   
def main(s,t):


  l=[0]

  r=[0]

  for i in range(len(s)):

    prev_idx=l[-1]
    if prev_idx<len(t) and s[i]==t[prev_idx]:
      prev_idx+=1 
    l.append(prev_idx)

  for i in range(len(s)-1,-1,-1):
    prev_idx=len(t)-r[-1]-1 
    last_val=r[-1]
    if prev_idx>-1 and s[i]==t[prev_idx]:
      last_val+=1
    r.append(last_val)
  
  r=list(reversed(r))
  
  tree=[0]*(2*(len(t)+1)+1) 

  for i in range(len(t)):
    val=ord(t[i])-97
    u=1 
    u<<=val
    update(i+1,u,len(t)+1,tree)
  update(0,0,len(t)+1,tree)
  
  

  
  for i in range(len(s)):

    l_val=l[i]
    r_val=r[i+1]
 
    letter=ord(s[i])-97

    r_val=len(t)-r_val+1
    l_val=l_val+1  if l_val<len(t) else l_val
    r_val=r_val-1 if r_val>0 else r_val
    if (r_val-l_val)<=0:
     
      
      if l_val>r_val:
        l_val,r_val=r_val,l_val
      val=query(l_val,r_val,len(t)+1,tree) 
   
      val>>=letter 
      if val%2==0:
       
        return 'NO'
    
    else:
     
      return 'NO'
  return 'YES'

s=input()
t=input()
print(main(s,t))








  
  

    

