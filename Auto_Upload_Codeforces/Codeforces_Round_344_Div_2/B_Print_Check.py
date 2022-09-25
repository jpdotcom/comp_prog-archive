import math
from os import startfile
import random 
from queue import Queue
import time 



def main(n,m,k):
  arr=[[0 for j in range(m)] for i in range(n)]

  rows={}
  cols={}
  i=0
  for e in k:
    q,a,c=e 

    if q==1:
      
      rows[a-1]=(c,i)
    if q==2:
      cols[a-1]=(c,i)
    i+=1 
  
  for i in range(len(arr)):
    for j in range(len(arr[0])):

      a1,b1=(0,-1) if i not in rows else rows[i]
      a2,b2=(0,-1) if j not in cols else cols[j]
      if b1>b2:
        arr[i][j]=a1 
      else:
        arr[i][j]=a2
  for e in arr:
    print(*e)
  return


n,m,k=list(map(int,input().split()))
arr=[]
for i in range(k):
  arr.append(list(map(int,input().split())))
(main(n,m,arr))
