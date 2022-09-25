import math
def increase(arr,val):
    for  i in range(len(arr)):
        arr[i][0]+=val 
        arr[i][1]+=val 
    return arr
def main(tmie1,time2,l,r):

    
    ans=0
    for i in range(l,r+1):

        if i==l:
            
            time2=increase(time2,l)
        else:
            time2=increase(time2,1)
        found=False
        for e1 in time1:
            for e2 in time2:
                
                x1,y1=e1 
                x2,y2=e2 
                if x1>x2:
                    x1,y1=e2
                    x2,y2=e1 
                if x2<=y1:
                    
                    found=True 
        if found:
            ans+=1 
    return ans 

p,q,l,r=list(map(int,input().split()))
time1=[]
time2=[]
for i in range(p):
    time1.append(list(map(int,input().split())))
for i in range(q):
    time2.append(list(map(int,input().split())))
print(main(time1,time2,l,r))





    


