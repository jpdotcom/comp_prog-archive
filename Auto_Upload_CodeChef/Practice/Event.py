import sys
import math


convert={"monday":0,"tuesday":1,"wednesday":2,"thursday":3,"friday":4,"saturday":5,"sunday":6}
def main(arr):
    
    
    day1,day2,r1,r2=arr
    
    
    min_days=(day2-day1)%7+1  
    res=None
    for i in range(15):
        
        if r1<=min_days+7*i and min_days+7*i<=r2:
            
            if not res:
                res=min_days+7*i
            else:
                return "many"
    
    if not res:
        res='impossible'
    return res
    
    

for _ in range(int(input())):
    
    arr=input().split()
    
    arr[0]=convert[arr[0]]
    arr[1]=convert[arr[1]]
    arr=list(map(int,arr))
    print(main(arr))