import sys
import math

def main(modified):
    B_num=0
    A_num=0
    for i in range(16,31):
        B_num+=2**i
    for j in range(0,16):
        A_num+=2**j
    
    A=[]
    B=[]
    for e in modified:
        
        A.append(e&A_num)
        
        B.append((e&B_num)>>16)
    
    
        
   
    print(*A)
    print(*B)
    return

for i in range(int(input())):
    
    n=int(input())
    modified=[]
    for j in range(n):
        modified.append(int(input()))
    
        
    
    print("Case "+str(i+1)+":")
    main(modified)
        