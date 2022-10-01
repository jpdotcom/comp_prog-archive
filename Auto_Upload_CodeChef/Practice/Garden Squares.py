import sys
import math

def main(grid):
    
    ans=0
    for i in range(len(grid)):
        
        for j in range(len(grid[0])):
            first_point=grid[i][j]
            for k in range(j+1,len(grid[0])):
                second_point=grid[i][k]
                
                if first_point==second_point:
                    dist=k-j
                    
                    if i+dist<len(grid):
                        
                        thrid_point=grid[i+dist][j]
                        fourth_point=grid[i+dist][k] 
                        if second_point==thrid_point and second_point==fourth_point:
                            ans+=1
    return ans
for _ in range(int(input())):
    n,m=input().split()
    n=int(n)
    arr=[]
    for b in range(n):
        arr.append(list(input()))
    print(main(arr))
                
            

        