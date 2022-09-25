import math
import random
import sys
def main(arr):
    
    arr=[[arr[i],i] for i in range(len(arr))]
    arr.sort(key=lambda x:x[0],reverse=True)
    ans=[0]*(len(arr)+1)
    val=0;
    dist=1;
    neg=1;
    for freq,i in arr:
        val+=2*dist*freq
        ans[i+1]=dist*neg
        neg*=-1 
        dist+=1 if (neg==1) else 0

    return [val,ans]
        

out=[]
for i in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    out.append(main(arr))

for val,ans in out:
    print(val)
    print(*ans)


                






            
    
            
            

        


                    
                    

            
            