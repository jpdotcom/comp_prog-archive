def main(arr):
    
    arr.sort() 
    print(*arr)
    return 
n=int(input())
arr=list(map(int,input().split())) 
main(arr