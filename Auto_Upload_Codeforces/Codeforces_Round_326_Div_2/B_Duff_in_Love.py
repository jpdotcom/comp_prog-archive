import math
import random 
from queue import Queue
import time 
cache={}
def main(n):
    div=[]
    for i in range(1,int(math.sqrt(n))+1):
        if n%i==0:
            val1=n//i
            val2=i
            if val1!=val2:

                div.append(val1)
                div.append(val2)
            else:
                div.append(val1)
    div.sort()
    
    for i in range(len(div)-1,-1,-1):
        f=div[i] 
        valid=True
        for j in range(1,i+1):
            c=div[j]**2 
            if c>f:
                break 
            elif f%c==0:

                valid=False 
                break 
        if valid:
            return f

    return -1

n=int(input())
print(main(n))
