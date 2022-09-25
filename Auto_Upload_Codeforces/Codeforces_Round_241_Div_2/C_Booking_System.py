import math
import random 

def main(arr,tables):
    idx_arr={} 
    for i in range(len(arr)):
        val=arr[i]
        if val not in idx_arr:
            idx_arr[val]=[] 
        idx_arr[val].append(i+1) 
    table_arr={}
    for i in range(len(tables)):
        val=tables[i]
        if val not in table_arr:
            table_arr[val]=[] 
        table_arr[val].append(i+1) 
   
    arr.sort(key=lambda x: x[1],reverse=True)
    tot=0 
    ans=[]
    tables.sort()
   
    for i in range(len(arr)):
        p,c=arr[i] 
    
        if len(tables)==0:
           
            break
        l=0
        r=len(tables)-1 
        found=False
        while l<r:
            
            m=(l+r)//2 

            if tables[m]==p:
                
                ans.append([idx_arr[(p,c)][-1],table_arr[tables[m]][-1]])
               
                idx_arr[(p,c)].pop()
                table_arr[tables[m]].pop()
                tables.pop(m)
                found=True
                tot+=c 
                break
            elif tables[m]<p:
                l=m+1 
            else:
                r=m
        if not found:
            
            val=tables[r]
           
            
            if  val>=p:
               
               
                ans.append([idx_arr[(p,c)][-1],table_arr[tables[r]][-1]])
                idx_arr[(p,c)].pop()
                table_arr[tables[r]].pop()
                tables.pop(r)
                found=True
                tot+=c 
        
    print(len(ans),tot)
    for e in ans:
        print(*e) 
    return 

n=int(input()) 
arr=[]
for i in range(n):
    arr.append(tuple(map(int,input().split())))

m=int(input()) 
tables=list(map(int,input().split()))
(main(arr,tables))


    

