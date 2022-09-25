def main(arr,l):


    arr.sort()
    ans=0
    for e in arr:
        ans+=e*l 
        l=max(1,l-1)
    
    return ans

n,l=list(map(int,input().split()))

arr=list(map(int,input().split()))
print(main(arr,l)