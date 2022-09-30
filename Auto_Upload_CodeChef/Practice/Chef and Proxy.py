import sys
import math

def find_curr(att):
    ans=0
    for e in att:
        if e=="P":
            ans+=1
    return ans
def main(att):
    
    proxy=0
    curr_pres=find_curr(att)
    if curr_pres/len(att)>=0.75:
        return 0
    for i in range(2,len(att)-2):
        
        a=True if att[i-1]=="P" or att[i-2]=="P" else False
        b=True if att[i+1]=="P" or att[i+2]=="P" else False
        if a and b and att[i]!="P":
            proxy+=1 
            curr_pres+=1 
            att[i]="O"
        if curr_pres/len(att)>=0.75:
            
            return proxy
            
    return -1  

for i in range(int(input())):
    n=int(input())
    att=list(input())
    print(main(att))
    
    
    

        