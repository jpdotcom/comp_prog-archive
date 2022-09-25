def main(arr):
    
    ans=0 
    
    for e in arr:
        if sum(e)>1:
            ans+=1 
    print(ans)
    return 

n=int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))
main(arr