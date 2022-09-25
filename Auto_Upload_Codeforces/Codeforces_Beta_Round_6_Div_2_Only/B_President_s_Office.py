def main(arr,p):
    ans=set()
    p1=[]
    p2=[]
    p3=[]
    p4=[]
    
    for i in range(len(arr)):
        for j in range(len(arr[0])):

            if arr[i][j]==p:
                if p1:
                    
                    p3=[i,j]
                else:
                    p3=[i,j]
                    p1=[i,j] 
    p2=[p3[0],p1[1]]
    p4=[p1[0],p3[1]]

    for j in range(p1[1],p4[1]+1):
       
        i=p1[0]-1
        if i>=0:
            if arr[i][j]!='.':
                ans.add(arr[i][j])
                
    
    for j in range(p2[1],p3[1]+1):
        
        i=p2[0]+1
        
        if i<len(arr):
            if arr[i][j]!='.':
                
                ans.add(arr[i][j])
    for i in range(p1[0],p2[0]+1):
        
        j=p1[1]-1
        if j>=0:
            if arr[i][j]!='.':
                
                ans.add(arr[i][j])
   
    for i in range(p4[0],p3[0]+1):
        
        j=p3[1]+1
        if j<len(arr[0]):
            
            if arr[i][j]!='.':
                ans.add(arr[i][j])
    
    return len(ans)
        
n,m,p=list(map(str,input().split()))
arr=[]
for i in range(int(n)):
    arr.append(input())
print(main(arr,p))
       