import sys
import math

def isDynamic(arr):
    
    
    for i in range(2,len(arr)):
        if arr[i]!=arr[i-1]+arr[i-2]:
            return False
    return True
def main(arr):
    
    
    freq={}
    
    for e in arr:
        if e not in freq:
            freq[e]=0
        freq[e]+=1 
    new_arr=[]
    for e in freq:
        new_arr.append(freq[e])
    

    
    new_arr.sort()
    if len(arr)<=2:
        return "Dynamic"
    
    a=isDynamic(new_arr)
    new_arr[0],new_arr[1]=new_arr[1],new_arr[0]
    b=isDynamic(new_arr)
    if a or b:
        return "Dynamic"
    return "Not"

    
for _ in range(int(input())):
    print(main(input()))