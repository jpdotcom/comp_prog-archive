import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(arr,p):
  p+=96
  arr_c=[0]*(len(arr))
  idx=None
  for i in range(len(arr)-1,-1,-1):
    
    e=ord(arr[i])+1
    if e<=p:
      a=None if i-1<0 else ord(arr[i-1])
      b=None if i-2<0 else ord(arr[i-2])
      
      found=True
      
      while (a==e or b==e):

        e+=1

        if e>p:
          found=False
          break
      if found:
        idx=i 
        
        arr_c[idx]=chr(e) 
          
        letter=None
        for i in range(0,idx):
            
            arr_c[i]=arr[i] 
        
        for i in range(idx+1,len(arr_c)):
          a=None if i-1<0 else ord(arr_c[i-1])
          b=None if i-2<0 else ord(arr_c[i-2])
          if a!=97 and b!=97:
            letter=97 
          elif a!=98 and b!=98:
            letter=98
          else:
            letter=99
          
          arr_c[i]=chr(letter)
          
        
        return "".join(arr_c)

  return "NO"
n,p=list(map(int,input().split()))
s=input()
print(main(s,p))

   



 