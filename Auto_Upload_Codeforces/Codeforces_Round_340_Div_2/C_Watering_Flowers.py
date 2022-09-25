import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
from decimal import *
def main(coor,f):


  x1,y1=f[0] 
  x2,y2=f[1] 
  ans=float('inf')
  dist=[] 
  for e in coor:
    x3,y3=e
    d1=(x3-x2)**2+(y3-y2)**2 
    d2=(x3-x1)**2+(y3-y1)**2
    dist.append((d1,d2))
  for i in range(len(coor)+1):
    if i==0:
      r1=0
    else:
      r1=dist[i-1][0]
    r2=0
    for j in range(len(coor)): 

      d1,d2=dist[j]

      if d1>r1:
        r2=max(d2,r2) 
    ans=min(ans,r1+r2)
  return ans

n,x1,y1,x2,y2=list(map(int,input().split()))

coor=[] 

for i in range(n):
  coor.append(list(map(int,input().split())))
print(main(coor,[[x1,y1],[x2,y2]]))






    



   



 