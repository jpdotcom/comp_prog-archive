import math
import random 

def main(arr):
    ans=0
    start=[]
    for i in range(len(arr)-3):
        
        s=arr[i:i+4]
        if s=="bear":
            start.append(i)
    
    for i in range(len(start)):
        left=-1 if i==0 else start[i-1]
        right=len(arr) 
        
        ans+=(start[i]-left)*(right-(start[i]+3))
        
            
    return ans

s=input()
print(main(s)