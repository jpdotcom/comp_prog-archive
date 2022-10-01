import heapq


import math
from math import log10
def getsmall(arr,k):
    mod=1000000007
    ans=[arr[0]]
    
    
    a=[(log10(arr[0]),0)]
    
    heapq.heapify(a)
    
    for i in range(1,len(arr)):
        
        
        val=log10(arr[i])
        
        while a[0][1]<(i-k):
            heapq.heappop(a)
        val+=a[0][0]
        ans.append((arr[i]*ans[a[0][1]])%mod)
        
        
        heapq.heappush(a,(val,i))
    
    return ans[len(arr)-1]
    
n,k=input().split()
arr=list(map(int,input().split()))
k=int(k)
print(getsmall(arr,k))