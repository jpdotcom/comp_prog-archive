import sys
import math

def main(SG,S,FG,T,D):
    
    
    diff_kph=(D*50*3600)/(1000*T)
    
    
    
    
    ans=S+diff_kph
    
    if abs(SG-ans)>abs(FG-ans):
        
        return "FATHER"
    elif abs(SG-ans)<abs(FG-ans):
        return "SEBI"
    return "DRAW"
        
for _ in range(int(input())):
    
    S,SG,FG,D,T=list(map(int,input().split()))
    print(main(SG,S,FG,T,D))