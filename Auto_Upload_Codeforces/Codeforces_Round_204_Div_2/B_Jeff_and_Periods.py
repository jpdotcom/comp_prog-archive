import math
import random 

def main(arr):
    pos={}
    for i in range(len(arr)):
        if arr[i] not in pos:
            pos[arr[i]]=[]
        pos[arr[i]].append(i) 
   
    ans=[]
    for e in pos:
       
        if len(pos[e])==1:
            ans.append([e,0])
            
        else:
            dist=pos[e][1]-pos[e][0]
            v=True
            for i in range(0,len(pos[e])-1):

                if pos[e][i+1]-pos[e][i]!=dist:
                    v=False 
            if v:
                ans.append([e,dist])
    ans.sort(key=lambda x:x[0])
    print(len(ans))
    for e in ans:
        print(*e)
            
                    
        





n=int(input())
arr=list(map(int,input().split()))
(main(arr)