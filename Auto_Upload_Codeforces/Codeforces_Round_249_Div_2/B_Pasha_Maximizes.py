import math
import random 

def main(arr,k):
  
  for i in range(len(arr)):
    
    if arr[i]!="9":
      curr_val=int(arr[i]) 
      
      dist=None
      for j in range(i+1,min(len(arr),i+k+1)):
        if curr_val<int(arr[j]):
          curr_val=int(arr[j])
          dist=j
      if dist!=None:
        k-=(dist-i)
        arr.pop(dist) 
        arr.insert(i,str(curr_val))
          
  return int("".join(arr))
 


n,k=list(map(int,input().split())) 
n=[c for c in str(n)]

print(main(n,k)