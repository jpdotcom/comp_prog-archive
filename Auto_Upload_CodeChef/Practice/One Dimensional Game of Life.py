import sys
import math

def main(arr):
    v=0
    sol=[]
    arr=list(map(int,arr))
    c=[(0,0),(0,1),(1,0),(1,1)]
    for e in c:
        a,b=e 
        
        new_arr=[0]*len(arr)
        
        new_arr[0]=a
        new_arr[1]=b 
        
        for i in range(1,len(arr)-1):
            
            if new_arr[i]==arr[i]:
                new_arr[i+1]=new_arr[i-1]
            else:
                new_arr[i+1]=new_arr[i-1]^1 
        
        if new_arr[-1]==arr[-1]:
            if new_arr[-2]==new_arr[0]:
                if new_arr[0]==arr[0]:
                    if new_arr[1]==new_arr[-1]:
                        v+=1 
                        sol=new_arr
                        
                else:
                    if new_arr[1]==new_arr[-1]^1:
                        v+=1 
                        sol=new_arr
                        
                    
        else:
            if new_arr[-2]==new_arr[0]^1:
                if new_arr[0]==arr[0]:
                    if new_arr[1]==new_arr[-1]:
                        v+=1 
                        sol=new_arr
                        
                else:
                    if new_arr[1]==new_arr[-1]^1:
                        v+=1 
                        sol=new_arr
                        
    
    if v==1:
        sol=list(map(str,sol))
        print("".join(sol))
    elif v>1:
        print("Multiple solutions")
    else:
        print("No solution")
    return
for i in range(int(input())):
    
    s=input()
    (main(s))
        