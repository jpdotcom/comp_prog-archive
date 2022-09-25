import math
import random 
from queue import Queue

  

def main(arr1,arr2):
    
    q1=Queue(maxsize=0)
    q2=Queue(maxsize=0)
    seen=set([])
    ans=0
    
    while len(arr1)!=0 and len(arr2)!=0:
        e=(tuple(arr1),tuple(arr2))
        if e not in seen:
            seen.add(e)
        else:
            print(-1)
            return
        val1=arr1.pop(0) 
        val2=arr2.pop(0)
        
        if val1>val2:
            arr1.append(val2)
            arr1.append(val1) 
        else:
            arr2.append(val1)
            arr2.append(val2)
        ans+=1 
    if len(arr1)==0:
        print(ans,2) 
    else:
        print(ans,1)
    return
n=int(input()) 

arr1=list(map(int,input().split()))[1:] 
arr2=list(map(int,input().split()))[1:]
(main(arr1,arr2))

                

    



    

