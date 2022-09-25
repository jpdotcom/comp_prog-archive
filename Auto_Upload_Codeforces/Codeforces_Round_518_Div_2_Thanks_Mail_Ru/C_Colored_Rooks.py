import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 



def main(n,edges):

  start=(1,1)
  colors={}
  for i in range(len(edges)):

    a,b=edges[i]

    if a not in colors:
      colors[a]=[start]
      
    else:
      prev_color_cord=colors[a][0]
      
      new_color_cord=start 

      colors[a].append((prev_color_cord[0],new_color_cord[1]))
      colors[a].append(start)
    
    start=(start[0]+1,start[1]) 
      

    if b not in colors:
      colors[b]=[start]
      
    else:
      prev_color_cord=colors[b][0]
      
      new_color_cord=start 

      colors[b].append((prev_color_cord[0],new_color_cord[1]))
      colors[b].append(start)
    start=(start[0]+1,start[1]+1)

  for i in range(1,n+1):
    if i not in colors:
      colors[i]=[start]
    start=(start[0]+1,start[1]+1)
  colors_list=[0]*(n+1)
 
  for e in colors:
    colors_list[e]=colors[e] 
  
  for i in range(1,len(colors_list)):
    
    print(len(colors_list[i]))

    for e in colors_list[i]:
      print(*e)
  

n,m=list(map(int,input().split()))
arr=[]
for i in range(m):
  arr.append(list(map(int,input().split())))
main(n,arr)







