import math
def main(arr):
    arr.sort() 
    
    n=len(arr)
    prefix=[arr[0]]
    for i in range(1,len(arr)):
        prefix.append(prefix[-1]+arr[i])
    ans=sum(arr)
    for i in range(len(arr)):
        s=0 
        if (i>0):
            s=prefix[i-1]
        val=(arr[i]*i-s+(prefix[-1]-prefix[i])-(n-1-i)*arr[i])
        
        ans+=val
    
    d=n 
    g=math.gcd(d,ans)
    print(ans//g,d//g)
    return
n=int(input())
arr=list(map(int,input().split()))
main(arr)
       