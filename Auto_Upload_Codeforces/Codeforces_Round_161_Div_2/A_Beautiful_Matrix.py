def main(arr):
    
    mid=2 
    
    
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i][j]==1:
                print(abs(i-mid)+abs(j-mid)) 
                return 
arr=[]
for i in range(5):
    arr.append(list(map(int,input().split())))
main(arr