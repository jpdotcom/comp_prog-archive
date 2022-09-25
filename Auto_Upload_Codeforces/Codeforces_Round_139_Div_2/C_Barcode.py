def main(arr,x,y):

    whites=[]
    blacks=[]

    for i in range(len(arr[0])):
        white,black=0,0
        for j in range(len(arr)):
            if arr[j][i]=='.':

                black+=1
            else:
                white+=1 
        whites.append(white)
        blacks.append(black)
    
    for i in range(1,len(whites)):
        whites[i]+=whites[i-1]
    for i in range(1,len(blacks)):
        blacks[i]+=blacks[i-1]
    
    whites=[0]+whites 
    blacks=[0]+blacks
    
    dp=[[float('inf') for k in range(2)] for i in range(len(arr[0])+1)]
    dp[0][0]=0
    dp[0][1]=0
    
    for i in range(1,len(dp)):
        for j in range(2):
            for k in range(x,y+1):
                if (i-k)>=0:
                    
                    if j==1:
                        
                        dp[i][j]=min(dp[i][j],blacks[i]-blacks[i-k]+dp[i-k][0])
                    elif j==0:
                        dp[i][j]=min(dp[i][j],whites[i]-whites[i-k]+dp[i-k][1])
    
    return (min(dp[-1][0],dp[-1][1]))
                    
    
n,m,x,y=list(map(int,input().split()))
arr=[]
for i in range(n):
    arr.append([c for c in input()])
print(main(arr,x,y))


                


