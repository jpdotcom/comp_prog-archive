import sys



    
def chess(arr,k):
    
    res=None
    ans=float('inf')
    for i in range(len(arr)):
        
        if k%arr[i]==0:
            
            if ans>k/arr[i]:
                ans=k/arr[i]
                res=arr[i]
    
    return -1 if res==None else res



for _ in range(int(input())):
    
    n,k=input().split()
    
    k=int(k)
    
    p=list(map(int,input().split()))
    
    res=chess(p,k)
    print(res)