def main(arr,x):
    
    
    s=sum(arr)
    sweets=int(s/x)
    for i in range(len(arr)):
        
        if int((s-arr[i])/x)==sweets:
            return -1
    return sweets


for i in range(int(input())):
    n,x=list(map(int,input().split()))
    
    arr=list(map(int,input().split()))
    print(main(arr,x))        