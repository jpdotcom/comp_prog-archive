import sys
import math

def main(arr,k):
    a=None
    
    for i in range(int(math.log2(k))+1):
        
        b=k/(2**i)
        if b ==int(b):
            a=b
    
    for e in arr:
        if e/a  != int(e/a):
            return 'NO'
    return 'YES'


            
            
    

for i in range(int(input())):
    n,k=list(map(int,input().split()))
    arr=list(map(int,input().split())) 
    print(main(arr,k))
            
            
    
    
    

        

        