import math 
import heapq 
from queue import Queue  


def main(n):

  if n<6:
    print(-1) 
  
  else:
    
    print(1,2) 
    print(2,3) 
    print(2,4)
    print(4,5)
    print(4,6) 
    a=7 
    while a<=n:
      print(2,a) 
      a+=1 

  a=2 
  while a<=n:
    print(1,a)
    a+=1

  return 

n=int(input())
(main(n))