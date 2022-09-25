import math
import random 

def main(arr,n):


   ans=0 
   owe=[0]*(n+1)
   for i in range(len(arr)):
       a,b,c=arr[i]
       owe[a]+=c 
       owe[b]-=c 
   
   return sum([x for x in owe if x>0])


n,m=list(map(int,input().split()))
arr=[]
for i in range(m):
    arr.append(list(map(int,input().split())))

print(main(arr,n)