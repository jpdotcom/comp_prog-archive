import math
import random
import sys

def main(s):
    
    if (len(s)==1 and (s[0]=="0" or s[0]=="_" or s[0]=="X")):
        return 1
    elif (s[0]=="0" and len(s)>1):
        return 0
    elif (len(s)==1):
        return 0
    mult1=1
    mult2=1
    f=False
    for i in range(len(s)-2): 

        if s[i]=="_":
            if (i!=0):
                mult1*=10
            else:
                mult1*=9
        elif s[i]=="X" and mult2==1:
            if (i!=0):
                mult2=10 
            else:
                mult2=9 
                f=True
    ans=0
    for i in range(100):
        if (i%25)!=0:
            continue
        val=list([c for c in str(i)]) 
        if (i==0):
            val=["0","0"]
        
        mult_val=mult2
        check=[s[-2],s[-1]]

        if check[0]=="X":
            if (val[0]=='0' and f):
                continue
            check[0]=val[0] 
            mult_val=1
            if check[1]=="X":
                
                check[1]=val[0] 
                
        if (check[1]=="X" and check[0] !="X"):
            if (val[1]=='0' and f):
                continue
            check[1]=val[1] 
            mult_val=1
        if (check[0]=="_"):
            check[0]=val[0]
        if (check[1]=="_"):
            check[1]=val[1] 
        if (val==check) and not (len(s)==2 and check[0]=="0"):
            ans+=mult_val*mult1

    return ans
    

            
s=input() 
print(main(s))



                    
                    

            
            