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
    
   
    for i in range(len(arr)):
        p,c=arr[i] 
        val=float('inf')
        idx_for_table=None
        for j in range(len(tables)):
            if tables[j]>=p:
                if val>tables[j]:
                    val=tables[j]
                    
        if val!=float('inf'):
            ans.append([idx_arr[(p,c)][-1],table_arr[val][-1]])
            idx_arr[(p,c)].pop()
            
            tables.remove(val)
            table_arr[val].pop()
            tot+=c 
    print(len(ans),tot)
    for e in ans:
        print(*e)
    
                
n=int(input()) 
arr=[]
for i in range(n):
    arr.append(tuple(map(int,input().split())))

m=int(input()) 
tables=list(map(int,input().split()))
(main(arr,tables))


    

