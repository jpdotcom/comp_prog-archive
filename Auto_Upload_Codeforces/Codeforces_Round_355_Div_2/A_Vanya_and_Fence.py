def main(arr,h):
    width=0 
    
    for e in arr:
        if e>h:
            width+=2 
        else:
            width+=1 
    print(width)
    return
    
n,h=list(map(int,input().split())) 
arr=list(map(int,input().split()))
main(arr,h