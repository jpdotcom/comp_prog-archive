import math
from os import startfile
import random 
from queue import Queue
import time 



def main(arr,a):

  s=sum(arr)
  ans=[]
  for i in range(len(arr)):
    x,y=0,0 

    sub_sum=s-arr[i] 
    x=a-sub_sum 
    y=a-(len(arr)-1)
    val=0
   
    if y+1<=arr[i]:
      val+=(arr[i]-y)
    if x-1>=1:
      val+=(x-1)
    ans.append(val)
      
    
  
  print(*ans)
  return 

n,a=list(map(int,input().split()))
arr=list(map(int,input().split()))
main(arr,a