import math
import random
import sys

def main(s):
    

    idx=len(s)-2
    isgreater=-1
    for i in range(len(s)-1):
        a=int(s[i])
        b=int(s[i+1])
        if (len(str(a+b))==2 ):
            idx=i 
            isgreater=1
        elif (isgreater==-1 and (a+b)>int(s[i])):
            idx=i
            isgreater=0 

    p=str(int(s[idx])+int(s[idx+1]))
    ans=s[:idx]+p+s[idx+2:]
    return ans;


t=int(input())
ans=[]
for i in range(t):
    s=input()
    ans.append(main(s))
for e in ans:
    print(e)

                






            
    
            
            

        


                    
                    

            
            