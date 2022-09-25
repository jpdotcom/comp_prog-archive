import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def main(arr,k):

  arr+='.'
  ans=0
 
  for e in k:

    a,b=e
    
    cnt1,cnt2=0,0
    for i in range(len(arr)):
    
      if arr[i]==a:
        cnt1+=1 
      elif arr[i]==b:
        cnt2+=1 
      else:
        
        ans+=min(cnt1,cnt2) 
        cnt1,cnt2=0,0
  return ans
          
    

    
    


  return ans 

s=input()
m=int(input())
k=[]
for i in range(m):
  k.append(input())
print(main(s,k))






