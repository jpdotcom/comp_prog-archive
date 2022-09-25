import math
import random
import sys
import time
def div(val,max_val):

    ans=set([])
    if (val==0):
        return ans
    for i in range(1,10**3+10):
        val2=val/i 
        if (val2==int(val2)):
            ans.add(int(val2))
            ans.add(i) 
    return ans

def main(n,arr):
    cnt={}
    ans=1
    for e in arr:
        if e not in cnt:
            cnt[e]=0
        cnt[e]+=1 
    for e in cnt:
        if cnt[e]>=n/2:
            return -1 
    cnt={}
    max_val=max([abs(e) for e in arr])+1
    for i in range(len(arr)):
        cnt={}
        add=0
        for j in range(len(arr)):
            if (arr[j]>=arr[i]):
                a=div(arr[j]-arr[i],max_val)
                if len(a)==0:
                    add+=1
                     
                for e in a:
                    if e not in cnt:
                        cnt[e]=0
                    cnt[e]+=1 
        for e in cnt:
            if cnt[e]+add>=n/2:
                ans=max(ans,e) 
    


    return ans

t=int(input()) 
out=[]
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split())) 
    out.append(main(n,arr)) 
for e in out:
    print(e)
                    

                    
                    

            
            