import sys
import math

def main(arr):
    
    freq={}
    for e in arr:
        s=int(e)
        
        if s not in freq:
            freq[s]=0
        freq[s]+=1 
   
    ans=[]
    for i in range(65,91):
        
        s=str(i)
        
        if int(s[0]) in freq:
            freq[int(s[0])]-=1 
            if int(s[1]) in freq and freq[int(s[1])]>0:
                ans.append(chr(i+32).upper())
            freq[int(s[0])]+=1 
    ans="".join(ans)
    return ans

t=int(input())

for i in range(t):
    n=input()
    print(main(n))
        