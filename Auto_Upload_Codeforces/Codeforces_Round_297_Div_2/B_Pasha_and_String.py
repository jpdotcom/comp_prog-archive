import math
import random 

def main(s,arr):


    r=[0]*len(s) 
    
    for i in range(len(arr)):
        idx=arr[i]-1 
        r[idx]+=1 
    for i in range(1,len(r)//2):
        r[i]+=r[i-1]
    
    
    ans=[c for c in s] 

    for i in range(len(r)//2):
        if r[i]&1:
            ans[i],ans[len(s)-i-1]=ans[len(s)-i-1],ans[i] 
    return "".join(ans)

s=input() 
m=int(input()) 
arr=list(map(int,input().split()))
print(main(s,arr))

