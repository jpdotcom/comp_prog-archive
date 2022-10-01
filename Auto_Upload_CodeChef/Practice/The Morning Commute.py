import sys
import math

def main(arr):
    
    
    time_passed=0
    for e in arr:
        x,l,f=e 
        
        
        temp=(time_passed-x)/f 
        
        if temp<0:
            time_passed+=(x-time_passed) 
        else:
            time_passed+=(math.ceil(temp)*f+x)-time_passed
        time_passed+=l 
    return time_passed
    
for i in range(int(input())):
    
    n=int(input())
    stations=[]
    for i in range(n):
        stations.append(list(map(int,input().split())))
        
    print(main(stations))
        
        

        