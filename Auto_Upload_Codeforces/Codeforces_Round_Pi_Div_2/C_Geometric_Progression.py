def main(arr,k,l=3):

  dp=[[0 for i in range(l+1)] for j in range(len(arr))]
  vals={}
  for i in range(len(dp)):

    dp[i][1]=1 
  
  for i in range(len(dp)):
    for j in range(2,len(dp[0])):

      val=arr[i]
      val_n=arr[i]/k 

      if val_n==int(val_n):
        val_n=int(val_n) 
        if (val_n,j-1) in vals:
          dp[i][j]+=vals[(val_n,j-1)]
      
      prev=dp[i][j-1]
      prev_val=arr[i] 
      if (prev_val,j-1) not in vals:
        vals[(prev_val,j-1)]=0 
      vals[(prev_val,j-1)]+=prev 
  
  ans=0
  
  for i in range(len(dp)):
    ans+=dp[i][l]
  return ans 
n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))

print(main(arr,k))

