import math
from os import curdir, startfile
import random 
from queue import Queue
import time 
import heapq
import sys 

def main(s,a,b):

  modulo_l=[0]

  modulo_r=[0] 


  for i in range(len(s)):
    prev=modulo_l[-1]
    num=int(s[i])%a
    modulo_l.append(((10%a*prev%a)%a+num%a)%a)
  modulo_l.pop(0)
  p=0
  for i in range(len(s)-1,-1,-1):
    
    num1=pow(10,p,b) 
    num2=int(s[i])%b
    num3=modulo_r[-1]%b 
    
    modulo_r.append(((num1*num2)%b+num3%b)%b)
    p+=1
  modulo_r=list(reversed(modulo_r))

  modulo_r.pop(-1)
  
  for i in range(0,len(modulo_l)-1):
    if modulo_l[i]==modulo_r[i+1] and modulo_l[i]==0 and s[i+1]!="0":

      print("YES")
      print(s[:i+1])
      print(s[i+1:])
      return 
  print("NO")
  return
s=input()
a,b=list(map(int,input().split()))
(main(s,a,b))



