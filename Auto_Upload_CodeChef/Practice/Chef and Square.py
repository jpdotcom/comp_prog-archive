import sys
import math

def main(arr):
    ans=2
    if len(arr)<2:
        return 4-len(arr)
    set_arr=set(arr)
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            need=2
            x1,y1=arr[i]
            x2,y2=arr[j]
            xc = (x1 + x2)/2  ;  yc = (y1 + y2)/2  ;    
            xd = (x1 - x2)/2  ;  yd = (y1 - y2)/2  ;    

            x3 = xc - yd  ;  y3 = yc + xd;    
            x4 = xc + yd  ;  y4 = yc - xd;    
            if (x3,y3) in set_arr:
                need-=1 
            if (x4,y4) in set_arr:
                need-=1
            ans=min(ans,need)
    return ans

arr=[]
for i in range(int(input())):
    arr.append(tuple(map(int,input().split())))
print(main(arr))
    
    
                

        