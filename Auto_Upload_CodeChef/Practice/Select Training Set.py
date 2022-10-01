import sys
import math

def main(arr):
    
    
    isTrue={}
    
    isFalse={}
    
    for i in range(len(arr)):
        word,val=arr[i]
        
        if word not in isFalse:
            isFalse[word]=0 
        if word not in isTrue:
            isTrue[word]=0 
        if val:
            isTrue[word]+=1 
        else:
            isFalse[word]+=1 
    ans=0
    for i in range(len(arr)):
        word,val=arr[i]
        
        if word in isTrue:
            if isTrue[word]>=isFalse[word]:
                ans+=isTrue[word]
            else:
                ans+=isFalse[word]
            del isTrue[word]
            del isFalse[word]
    return ans 
    

for _ in range(int(input())):
    
    n=int(input())
    arr=[]
    for b in range(n):
        word,val=input().split()
        val=int(val)
        arr.append([word,val])
    print(main(arr))
        
        

     