import sys
import math
from queue import Queue 
import heapq

def main(grid):
    
    dp=[[None for i in range(len(grid[0]))] for j in range(len(grid))]
    south=[[None for i in range(len(grid[0]))] for j in range(len(grid))]
    east=[[None for i in range(len(grid[0]))] for j in range(len(grid))]
    for i in range(n-1,-1,-1):
        for j in range(n-1,-1,-1):
            
            canSee=True if grid[i][j]=='.' else False
            if (i+1)<n:
                canSee=south[i+1][j] and canSee 
            south[i][j]=canSee
    
    for i in range(n-1,-1,-1):
        for j in range(n-1,-1,-1):
            
            canSee=True if grid[i][j]=='.' else False
            if (j+1)<n:
                canSee=east[i][j+1] and canSee 
            east[i][j]=canSee
    for i in range(n-1,-1,-1):
        for j in range(n-1,-1,-1):
            
            canSee=True if grid[i][j]=='.' else False
            if (i+1)<n:
                canSee=south[i+1][j] and canSee
            if (j+1)<n:
                canSee=east[i][j+1] and canSee
            dp[i][j]=canSee 
            
                
    ans=0
    for i in range(n):
        for j in range(n):
            if dp[i][j]:
                ans+=1 
    print(ans)
            
    

t=int(input())
for i in range(t):
    n=int(input())
    arr=[]
    for j in range(n):
        s=input()
        arr.append([c for c in s])
    main(arr)
        