import math
    
def main(arr,t,c):


    
    l=0 
    ans=0
    for e in arr:
        if e<=t:
            l+=1 
        else:
            

            ans+=max(0,l-c+1)
            l=0
    ans+=max(0,l-c+1)
    return ans
n,t,c=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,t,c))
            
 