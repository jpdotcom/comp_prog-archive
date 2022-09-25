
import math 
import sys
def valid(arr,w,val,m):


  change=[0]*len(arr)
  add=0
  for i in range(len(arr)):
    add+=change[i] 
    arr[i]+=add 
    if arr[i]<val:
      
      
      e=i+w
      add+=val-arr[i]

     
      if e<len(arr):

        change[e]-=(val-arr[i])
      m-=(val-arr[i])
  
  if m<0:
    return False 
  return True 

def main(arr,w,m):


  l=0 
  r=10**9+10**5+1 
  best=0
  while l<=r:
    mid=(l+r)//2 
    arr_copy=arr.copy()
    if valid(arr_copy,w,mid,m):
      best=mid 
      l=mid+1 
    else:
      r=mid-1
  return best



n,m,w=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,w,m))
     
      


  
    
      
     