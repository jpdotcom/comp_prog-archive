import math
import random 

def main(n,arr,holes):


    
    if 1 in holes:
        return 1
    bone_pos=1
    for i in range(len(arr)):
        
        j,k=arr[i] 
        if j==bone_pos:

            if k in holes:
                return k
            else:
                bone_pos=k
                
        elif k==bone_pos:
            if j in holes:
                return j 
            else:
                bone_pos=j
        
    return bone_pos 

n,m,k=list(map(int,input().split()))
holes=set(map(int,input().split()))
arr=[]
for i in range(k):
    arr.append(list(map(int,input().split())))
print(main(n,arr,holes))



    

