
import math 
import sys
def main(arr):
  
  
  for i in range(len(arr)):
    a,b=arr[i] 
    arr[i]=[a,b,i]
  
  arr.sort(key=lambda x:(x[1],x[0]))
  ans=[0]*len(arr)
  next_val=0
  taken=set()
  for i in range(len(arr)):

    l,r,idx=arr[i] 
    start=l 
    while start in taken:
      start+=1 

    
    ans[idx]=start
    taken.add(start)
  print(*ans)




n=int(input())
arr=[list(map(int,input().split())) for i in range(n)]
(main(arr))
     
      


  
    
      
     