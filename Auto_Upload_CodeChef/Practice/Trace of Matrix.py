import sys
import math

def main(arr):
    ans=-float('inf')
    
    for i in range(len(arr)):
        a=len(arr[0]) if i==0 else 1
        for j in range(a):
            
            start=[i,j]
            
            temp=0
            
            while start[0]<len(arr) and start[1]<len(arr):
                temp+=arr[start[0]][start[1]]
                start[0]+=1 
                start[1]+=1
                
            
            ans=max(ans,temp)
    
    return ans
for _ in range(int(input())):
    n=int(input())
    arr=[]
    for j in range(n):
        arr.append(list(map(int,input().split())))
    print(main(arr))
        
        