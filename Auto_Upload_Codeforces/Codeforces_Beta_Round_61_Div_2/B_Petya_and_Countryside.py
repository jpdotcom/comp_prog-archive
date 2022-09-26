def main(arr):
    
    ans=0
    for i in range(len(arr)):
        temp_ans=1
        for j in range(i-1,-1,-1):
            if arr[j]<=arr[j+1]:
                temp_ans+=1 
            else:
              break
        for j in range(i+1,len(arr)):
            if arr[j]<=arr[j-1]:
                temp_ans+=1 
            else:
              break
        ans=max(temp_ans,ans) 
    return ans 

n=int(input())
arr=list(map(int,input().split())) 
print(main(arr)