
import math 
import sys
def main(arr):
  left={}
  right={}
  for e in arr:
    if e not in right:
      right[e]=0 
    right[e]+=1 
  
  prefix=[arr[0]]
  for i in range(1,len(arr)):
    prefix.append(arr[i]+prefix[-1])
  s=prefix[-1]
  for i in range(len(arr)):

    if arr[i] not in left:
      left[arr[i]]=0 
    left[arr[i]]+=1 
    right[arr[i]]-=1 
    a=prefix[i] 
    b=s-prefix[i]
    
    if prefix[i] == s-prefix[i]:
      return 'YES'
    else:
      if a>b:
        if (a-b)/2 in left and left[(a-b)/2]!=0:
          return 'YES'
      else:
        
        if (b-a)/2 in right and right[(b-a)/2]!=0:
          return "YES"
  return "NO"

n=int(input())
arr=list(map(int,input().split()))
print(main(arr))
     
      


  
    
      
     