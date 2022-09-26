def main(arr,a):
    
    a-=1
    ans=1 if arr[a] else 0
    n=len(arr)
    if a<=n//2:
        for i in range(a+1,len(arr)):
            
            dist=i-a
            c=0
            if a-dist>=0:
                
                c+=arr[a-dist] 
                c+=arr[i]
                if c==2:
                    ans+=2
            else:
                ans+=arr[i] 
    else:
        for i in range(a-1,-1,-1):
            
            dist=a-i
            c=0
            if a+dist<n:
                c+=arr[a+dist] 
                c+=arr[i]
                if c==2:
                    ans+=2
            
            else:
                ans+=arr[i]
  
    return ans 
    
n,a=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,a))
                
       