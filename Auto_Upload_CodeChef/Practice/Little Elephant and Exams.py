import sys
import math
def find_prob(bolean,arr,ans,idx):
        
        if idx==len(arr):
            
            return ans
        prob,a,b=arr[idx] 
        x,y=0,0
        if  not bolean[a]:
            bolean[a]=True
            x=find_prob(bolean,arr,ans*prob/100,idx+1)
            bolean[a]=False
        if not bolean[b]:
            bolean[b]=True 
            y=find_prob(bolean,arr,ans*(1-(prob/100)),idx+1)
            bolean[b]=False
        if bolean[a] and bolean[b]:
            
            return 0
        
        return x+y
def main(arr):
    ans=1
   
        
    boolean=[False]*17
    print(find_prob(boolean,arr,ans,0))
for _ in range(int(input())):
    arr=[]
    for j in range(int(input())):
        arr.append(list(map(int,input().split())))
    main(arr)
    

        