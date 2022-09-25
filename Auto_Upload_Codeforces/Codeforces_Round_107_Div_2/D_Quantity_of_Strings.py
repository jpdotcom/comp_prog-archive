
import math 
def p(s):

  for i in range(len(s)//2):
    if s[i]!=s[len(s)-i-1]:
      return False 
  return True 
def main(n,m,k):
  mod=10**9+7
  if k==1 or k>n:
    return pow(m,n,mod)
  elif k==n:
    return pow(m,(n+1)//2,mod)
  ans=m
  if m<2:
    return ans 
  arr=[0,1]
  for i in range(n-2):
    arr.append(arr[-2])
  
  add=True 
  for i in range(n-k+1):
    
    if p(arr[i:i+k])==False:
      add=False 
      break 
  if add:
    ans=m*m 
  return ans  
  




n,m,k=list(map(int,input().split()))
print(main(n,m,k))
  
    
      
     