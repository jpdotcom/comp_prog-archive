import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr,k):
  arr.sort() 
  cnt={} 
  for e in arr:
    if e not in cnt:
      cnt[e]=0 
    cnt[e]+=1 
  
  s=sum([cnt[e] for e in cnt]) 
  prev=0
  idx1=None
  for e in cnt:
    
    if prev+cnt[e]*s<k:
      prev+=cnt[e]*s 
    else:
      idx1=e
      break 
  
  k-=prev 

  val=[(cnt[e],e) for e in cnt]
  
  i=-1
  while k>0:
    i+=1
    k-=cnt[idx1]*val[i][0] 
  print(idx1,val[i][1])
  return
  

  
  

n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))
main(arr,k)
    
        





    



   



 