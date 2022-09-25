import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(a,b):


  
  s1=int(math.sqrt(a))
  s2=int(math.sqrt(b))
  for i in range(1,a+1):
    for j in range(1,b+1):

      c,d=i,math.sqrt(a**2-i**2)
      x,y=-1*j,math.sqrt(b**2-j**2)
      
      if d==int(d) and y==int(y) and y!=0 and x!=0 and c!=0 and d!=0 and c!=x and d!=y:
        if (c*x+d*y)==0:

          print("YES")
          print(0,0)
          print(int(c),int(d))
          print(int(x),int(y))
          return 
  print("NO")
  return
a,b=list(map(int,input().split()))
(main(a,b))

   



 