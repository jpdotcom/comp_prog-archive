
import math 
import sys
def search(arr,l,r,p1,p2):


  
  i1=-1
  i2=-1
  copy_l=l 
  copy_r=r
  while l<=r:
    m=(l+r)//2 
    val=arr[m]
    if p1<=val and val<=p2:
      i1=m
      r=m-1 
    elif val>p2:
     
      r=m-1 
    else:
      l=m+1
  l=copy_l 
  r=copy_r
  while l<=r:
    m=(l+r)//2 
    val=arr[m]
    if p1<=val and val<=p2:
      i2=m
      l=m+1 
    elif val>p2:
     
      r=m-1 
    else:
     
      l=m+1
  if i1==-1 or i2==-1:
    return 0 
  else:
    return i2-i1+1
def main(arr):

  n=len(arr) 
  
  for i in range(len(arr)):
    arr[i].sort()
  ans=0
  for i in range(len(arr)):

    f_arr=arr[(i-1)%n]
    s_arr=arr[(i+1)%n]
    
    for j in range(len(arr[i])-1):
      p1=arr[i][j]
      p2=arr[i][j+1]
      val1=search(f_arr,0,len(f_arr)-1,p1,p2)
      val2=search(s_arr,0,len(s_arr)-1,p1,p2)

      if val1!=val2:
        ans+=1 
  return ans
      


    


n=int(input())
arr=[] 
for i in range(n):

  arr2=list(map(int,input().split()))
  arr2.pop(0)
  arr.append(arr2)
print(main(arr))

     
      


  
    
      
     