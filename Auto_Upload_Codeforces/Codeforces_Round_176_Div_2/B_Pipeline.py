def main(n,k):

  s=k*(k+1)//2
  if s<n:
    return -1
  l=1 
  r=k
  while l<=r:
   
    mid=(l+r)//2 
    
    curr=s-(mid*(mid-1))//2
    
    if curr==n:
     
      return k-mid+1 
    elif curr<n:
      r=mid-1
    else:
      l=mid+1 
  
  
  return k-l+2 


n,k=list(map(int,input().split()))
n-=1 
k-=1 
if n==0:
  print(0)
else:
  print(main(n,k))

      
