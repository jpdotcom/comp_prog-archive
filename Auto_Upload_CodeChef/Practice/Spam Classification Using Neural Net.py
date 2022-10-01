import sys
import math

def attack(arr,minX,maxX):
    
    init=minX&1 
    weight_sum=1
    for i in range(len(arr)):
        
        weight,bias=arr[i]
        weight=weight&1
        bias=bias&1        
        init=init*weight+bias
        
        weight_sum*=weight
    spam=0
    not_spam=0
    run=maxX-minX+1
    if init&1==0 and weight_sum&1==0:
        not_spam+=run
    
    elif init&1==1 and weight_sum&1==0:
        spam+=run
    
    else:
        if run&1==0:
            spam+=run/2
            not_spam+=run/2
        
        elif init&1==0:
            not_spam+=(run+1)/2
            spam+=(run-1)/2
        else:
            spam+=(run+1)/2
            not_spam+=(run-1)/2
            
            
            
        
        
        
        
    ans=[int(not_spam),int(spam)]        
    print(*ans)
    return

for _ in range(int(input())):
    
    
    n,minX,maxX=input().split()
    minX,maxX=int(minX),int(maxX)
    arr=[]
    for _ in range(int(n)):
        a,b=input().split()
        
        arr.append((int(a),int(b)))
    (attack(arr,minX,maxX))
    

        