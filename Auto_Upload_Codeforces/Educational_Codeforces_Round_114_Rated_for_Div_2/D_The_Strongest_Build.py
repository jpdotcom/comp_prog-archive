import math
import random
import sys
import heapq
def main(n,arr,invalid,m):


    invalid=set(invalid) 

    
    curr=tuple([len(arr[i])-1 for i in range(len(arr))])
    s=sum([arr[i][-1] for i in range(len(arr))])
    best=[(-1*s,curr)]
    heapq.heapify(best) 
    s,curr=heapq.heappop(best)
    seen=set()
    while (m!=0):
        if curr not in invalid:
            break
        
        for i in range(len(curr)):
            l=list(curr)
            if (l[i]!=0):
                l[i]-=1 
                t_l=tuple(l)
                if (t_l not in seen):
                     next_val=-1*s 
                     next_val-=arr[i][l[i]+1] 
                     next_val+=arr[i][l[i]]
                     next_val*=-1
                     heapq.heappush(best,(next_val,t_l))
                     seen.add(t_l)
        s,curr=heapq.heappop(best)
        m-=1
    curr=[curr[i]+1 for i in range(len(curr))]
    print(*curr)
    return
            

            

            

n=int(input())
arr=[] 
for i in range(n):

    temp=list(map(int,input().split())) 
    temp.pop(0) 
    arr.append(temp) 
m=int(input()) 
arr2=[]
for i in range(m):
    temp=list(map(int,input().split()))
    temp=[temp[i]-1 for i in range(len(temp))]
    temp=tuple(temp)
    arr2.append(temp)

main(n,arr,arr2,m)
