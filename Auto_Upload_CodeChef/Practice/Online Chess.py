import sys
import math

def main(arr):
    
    
    
    for e in arr:
        e[0]=int(e[0])
        e[2]=int(e[2])
        e[1]=int(e[1])
        e[3]=int(e[3])
        e+=[True]

    ans=['wait']
    for i in range(1,len(arr)):
        p1=arr[i]
        for j in range(0,i):
            p2=arr[j]
            if p2[-1]:
                if p2[1]<=p1[0] and p1[0]<=p2[2] and p1[1]<=p2[0] and p2[0]<=p1[2]:
                    if p2[3]==p1[3] and p2[4]==p1[4]:
                        if (p1[5]=='random' and p2[5]=='random') or (p1[5]=='black' and p2[5]=='white') or ((p2[5]=='black' and p1[5]=='white')):
                            ans+=[j+1] 
                            p1[-1]=False 
                            p2[-1]=False
                            
                            break
            if j==i-1:
                ans+=['wait'] 
    for e in ans:
        print(e)
t=int(input())

for i in range(t):
    n=int(input())
    arr=[]
    for j in range(n):
        arr.append(list(map(str,input().split())))
    (main(arr))
        
        
    

        