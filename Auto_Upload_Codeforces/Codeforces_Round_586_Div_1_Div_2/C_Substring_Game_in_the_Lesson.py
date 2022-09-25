import math
from os import startfile
import random 
from queue import Queue
import time 
import heapq
import sys 
def main(s):


  min_letter=float('inf')


  for i in range(len(s)):
    if ord(s[i])>min_letter:
      print('Ann')
    else:
      print('Mike')
    min_letter=min(ord(s[i]),min_letter)
  return  

main(input())





