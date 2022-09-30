import sys
import math

def main(arr,queries):
    
    
    
    work=[0]*32
    
    
    for e in arr:
        
        day,questions=e 
        
        work[day]=questions
    for i in range(1,len(work)):
        work[i]=work[i]+work[i-1]
    
   
    for e in queries:
        
        i,j=e 
        
        if work[i]>=j:
            print("Go Camp")
        else:
            print("Go Sleep")
    
for _ in range(int(input())):
    
    d=int(input())
    arr=[]
    for s in range(d):
        arr.append(list(map(int,input().split())))
    arr.sort(key=lambda x :x[0])
    q=int(input())
    queries=[]
    for t in range(q):
        queries.append(list(map(int,input().split())))
    (main(arr,queries))
        
        

        