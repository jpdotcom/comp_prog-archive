import heapq
class Node:

  def __init__(self,idx,freq,val) -> None:
      self.value=val 
      self.index=idx 
      self.occ=freq 
      self.front=None 
      self.back=None 
class LinkedList:

  def __init__(self) -> None:
      self.head=None
      self.h=[]
      self.seen=[False]*200001
      heapq.heapify(self.h) 
      self.ans=0
      self.len=0
  def insert(self,node) -> None:
    
    if self.head==None:
      self.head=node 
    else:
      h=self.head 
      node.back=h 
      h.front=node 
      self.head=node 
      node.front=None 
    self.len+=1 
    heapq.heappush(self.h,(-1*node.occ,node.index,node)) 
  def merge(self,l,r): 
    ll=l.back 
    rr=r.front 
    
    new_node=Node(min(r.index,l.index),l.occ+r.occ,l.value) 
    new_node.front=rr 
    new_node.back=ll 
    self.seen[max(l.index,r.index)]=True 
    if (rr!=None):
      rr.back=new_node 
      
    if (ll!=None):
      ll.front=new_node
    heapq.heappush(self.h,(-1*new_node.occ,new_node.index,new_node)) 
    return 
  def remove(self,node):
    self.len-=1 
    if (self.head==node and self.len==0):
      self.head=None 

      return 
    l=node.back
    r=node.front 
    if (l!=None):
      l.front=r 
    if r!=None:
      r.back=l 

    if (l!=None and r!=None and l.value==r.value):

      self.merge(l,r) 
  def next_val(self):
    if len(self.h)==0:
      return -1
    f,idx,node=heapq.heappop(self.h) 
    if (not self.seen[idx]):
    
      self.seen[idx]=True 
      self.remove(node)
      self.ans+=1 
    return 1
def main(n,arr):

  nodes=[]
  val=arr[0] 
  idx=0 
  freq=1 
  for i in range(1,len(arr)):
    if (arr[i]!=arr[i-1]):
      node=Node(idx,freq,val) 
      nodes.append(node) 
      val=arr[i] 
      idx+=1 
      freq=1 
      
    else:
      freq+=1 
 
  node=Node(idx,freq,val) 
  nodes.append(node) 
  l=LinkedList()
  for i in range(len(nodes)-1,-1,-1):
    l.insert(nodes[i])
  s=l.next_val() 
  while (s!=-1):
    s=l.next_val() 
  return l.ans 
n=int(input()) 
arr=list(map(int,input().split())) 
print(main(n,arr))






 