import math
import random 
from queue import Queue
import time 



def main(arr,d):

  ans=0
  for i in range(len(arr)):

    start=i 
    end=len(arr)-1
    mid=(start+end)//2
    best_val=mid
    while start<=end:
      
      mid=(start+end)//2 
     
      if arr[mid]-arr[i]==d:
        best_val=mid
        
        break 
      elif arr[mid]-arr[i]>d:
        
        end=mid-1
        best_val=end
      else:
        start=mid+1
        best_val=mid
    
    ans+=(best_val-i-1)*(best_val-i)//2 

  return ans

n,d=list(map(int,input().split()))
print(main(list(map(int,input().split())),d)