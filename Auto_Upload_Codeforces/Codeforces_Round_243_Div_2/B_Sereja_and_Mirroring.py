def valid(n,arr):
 
    if n!=int(n):
        return len(arr)
    n=int(n)
    for i in range(0,n):
        if arr[i]==arr[2*n-1-i]:
            continue 
        else:
            return len(arr) 
    if n==0:
        return 0
    curr_ans=n
    return min(curr_ans,valid(n/2,arr))
def main(arr):
    return valid(len(arr)/2,arr)
 

n,m=list(map(int,input().split()))
arr=[] 
for i in range(n):
    arr.append(list(map(int,input().split())))
print(main(arr))
