import sys
import math

def digit_sum(string):
    ans=0
    for e in string:
        ans+=int(e)
    return ans
def main(rounds):
    
    c=0
    m=0
    for str1,str2 in rounds:
        
        a=digit_sum(str1)
        b=digit_sum(str2)
        
        if a>b:
            c+=1 
        elif b>a:
            m+=1
        else:
            c+=1 
            m+=1
    if c>m:
        print(0,c)
    elif m>c:
        print(1,m)
    else:
        print(2,m)
    return
            
for _ in range(int(input())):
    rounds=[]
    for j in range(int(input())):
        
        rounds.append(input().split())
    main(rounds)