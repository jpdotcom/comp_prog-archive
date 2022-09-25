import math
import random 
from queue import Queue
import time 



def main(arr,m):

  m=list(reversed(m))

  arr=list(reversed(arr))

  
  start=sum(arr)
  possible_ans=[]
  l=0
  for i in range(len(arr)):

    if m[i]=="0":
      start-=arr[i] 
    else:
      l+=arr[i]
      if start-arr[i]>arr[i]:
        possible_ans.append(start-arr[i])
      else:
        possible_ans.append(arr[i])
  possible_ans.append(l)
  return max(possible_ans)

n=int(input())
arr=list(map(int,input().split()))
m=input()
print(main(arr,m)