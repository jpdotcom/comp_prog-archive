import math
import random 
from queue import Queue
import time 
cache={}
def main(n):
    ans=n
    start=int(math.sqrt(n))
    for i in range(2,start+1):
        while (ans%(i**2)==0):
            ans//=i
        
    return ans

n=int(input())
print(main(n)