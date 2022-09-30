import sys
import math
def findlog(p):
    x=0
    while p!=0:
        x+=1
        p//=2
    return x-1
def main(n):
    
    term=2**findlog(n)-1
    ans=[0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1]
    
    print(ans[term%60])
    
        
    
    return 

for _ in range(int(input())):
    (main(int(input())))

        