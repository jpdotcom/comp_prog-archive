import math
import random 
from queue import Queue

  
def main(arr):

    x_val={}
    y_val={}
    same_val={}
    for i in range(len(arr)):
        x,y=arr[i] 
        if x not in x_val:
            x_val[x]=0
        if y not in y_val:
            y_val[y]=0 
        if (x,y) not in same_val:
            same_val[(x,y)]=0
        y_val[y]+=1
        x_val[x]+=1
        same_val[(x,y)]+=1
    ans=0
    for e in arr:
        x,y=e 
        
        ans+=x_val[x]+y_val[y]-same_val[(x,y)]-1
        x_val[x]-=1 
        y_val[y]-=1 
        same_val[(x,y)]-=1

    return ans 

arr=[] 
n=int(input()) 
for i in range(n):
    arr.append(list(map(int,input().split())))
print(main(arr))

