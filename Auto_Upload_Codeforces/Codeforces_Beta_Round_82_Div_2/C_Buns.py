def main(arr,n,doug,cost):


  dp=[[0 for i in range(len(arr)+1)] for j in range(n+1)]

  
  dp[0]=[0 for i in range(len(arr)+1)]

  for i in range(1,n+1):
    for j in range(0,len(arr)+1):
      if j==0:
        a,b,c,d=50000000,1,doug,cost
      else:
        a,b,c,d=arr[j-1]

      for k in range(0,min(a//b,i//c)+1):
        if j==0:
          dp[i][j]=max(cost*k+dp[i-c*k][j],dp[i][j])
        else:
          
          dp[i][j]=max(d*k+dp[i-c*k][j-1],dp[i][j])
        
  return dp[-1][-1] 

n,m,doug,cost=list(map(int,input().split()))
arr=[]
for i in range(m):
  arr.append(list(map(int,input().split())))
print(main(arr,n,doug,cost))

