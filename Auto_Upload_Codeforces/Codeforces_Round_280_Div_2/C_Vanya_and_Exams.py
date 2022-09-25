import math
import random 

def main(arr,r,avg):
    n=len(arr)
    arr.sort(key=lambda x:x[1])
    s=sum([x[0] for x in  arr])
    if s/n>=avg:
        return 0
    ans=0
    for e in arr:
        a,b=e
        val1=r-a
        val2=n*avg-s
        if val1<=val2:
            ans+=val1*b 
            s+=val1 
        else:
            ans+=val2*b 
            return ans 
    return ans
    
n,r,avg=list(map(int,input().split()))
arr=[] 
for i in range(n):
    arr.append(list(map(int,input().split())))
print(main(arr,r,avg))






    

