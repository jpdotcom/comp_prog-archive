import math
import random 
from queue import Queue
import time 



def main(n):
  n=n**2 
  if n==1 or n==4:
    print(-1)

  elif n%2==1:
    print((n+1)//2,(n-1)//2)
  else:
    print((n//4+1),((n//4+1)-2))
  return
n=int(input())
main(n