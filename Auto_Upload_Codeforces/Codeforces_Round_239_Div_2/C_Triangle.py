import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(a,b):


  
  
  for i in range(1,a+1):
    
    c,d=i,math.sqrt(a**2-i**2)

    x,y=-1*b/a*d,b/a*c
    if b*d%a==0:
      x=int(x) 
    if b*c%a==0:
      y=int(y)
    if x==int(x) and y==int(y) and c==int(c) and d==int(d) and c!=x and d!=y and c!=0 and d!=0 and x!=0 and y!=0:
      print("YES")
      print(0,0)
      print(int(x),int(y))
      print(int(c),int(d))
      return 
  print("NO")
  return
a,b=list(map(int,input().split()))
(main(a,b))

   



 