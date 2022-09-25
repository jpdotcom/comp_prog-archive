def main(arr):


  max_val=-float('inf')

  ans=0
  temp_ans=0
  inc=0
  for i in range(len(arr)):
    arr[i]+=inc
    if arr[i]>=max_val:
      
      max_val=arr[i]
    else:
      ans+=max_val-arr[i]
      inc+=max_val-arr[i]

  ans+=temp_ans
  return ans
  

n=int(input())
arr=list(map(int,input().split()))
print(main(arr)