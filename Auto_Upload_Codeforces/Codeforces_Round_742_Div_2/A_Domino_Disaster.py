import math
import heapq
from queue import Queue

def main(arr):

  other=[]
  for i in range(len(arr)):
    if arr[i]=='U':
      other.append('D')
    elif arr[i]=='D':
      other.append('U')
    else:
      other.append(arr[i])
  
  return "".join(other)

t=int(input())
ans=[] 
for i in range(t):
  n=int(input())

  ans.append(main(input()))
for e in ans:
  print(e