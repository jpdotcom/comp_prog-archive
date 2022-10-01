import sys
import math

def main(n):
    
    
    m=[[0]*n for i in range(n)]
    start=1
    for i in range(n):
        m[0][i]=start
        start+=1
    for i in range(1,n):
        for j in range(n):
            m[i][j]=n+m[i-1][j]
    if n%2==0:
        for i in range(1,n):
            if i%2:
                p,q=0,n-1
                while p<q:
                    m[i][p],m[i][q]=m[i][q],m[i][p]
                    p+=1 
                    q-=1
    for e in m:
        print(*e)
    return 
for _ in range(int(input())):
    n=int(input())
    (main(n))
    
    

        