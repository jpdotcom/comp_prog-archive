import sys
import math

def main(n,k,s):
    need=0
    curr=0
    days=0
    date=0
    for i in range(s):
        date=(date+1)%7
        days=days+1 if date!=0 else days
        
        if curr<k:
            
            while days!=0 and curr<k:
                
                curr+=n 
                days-=1
                need+=1
            if curr<k:
                return -1
        curr-=k
    return need

for i in range(int(input())):
    n,k,s=list(map(int,input().split()))
    print(main(n,k,s))

        