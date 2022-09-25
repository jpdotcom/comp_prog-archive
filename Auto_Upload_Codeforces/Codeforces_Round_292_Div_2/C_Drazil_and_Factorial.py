import math
import random 

def find(n,facs):

    
    for i in range(len(facs)):
        if facs[i]!=1:

            num=n/facs[i] 
            if num==1:
                return [i]
            elif num==int(num):
                s=find(num,facs)
                if len(s)!=0:
                    return [i]+s
    return [] 

def main(n):
    facs=[1]

    for i in range(1,10):
        facs.append(i*facs[-1]) 
    
    ans=[]
    cache={}
    for i in range(len(n)):
        d=facs[int(n[i])]
        if d in cache:
            ans+=cache[d]

        else:
            l=find(d,facs)
            ans+=l 
            cache[d]=l
        
        
        
                
    
    ans.sort(reverse=True)
    ans=[str(x) for x in ans]
    return "".join(ans)
a=int(input())
n=input()
print(main(n))
                

    



    

