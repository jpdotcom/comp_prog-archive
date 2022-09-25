def main(arr,l,r,q1,q2):

  n=len(arr)
  prefix=[0] 

  for i in range(len(arr)):
    prefix.append(prefix[-1]+arr[i])
  ans=float('inf')
  
  for i in range(0,n+1):

    left=i 
    right=n-i 

    left_s=prefix[left] 
    right_s=prefix[-1]-left_s
    if left==right:
      ans=min(ans,left_s*l+right_s*r+(q1*(left-right)))

    elif left>right:
      ans=min(ans,left_s*l+right_s*r+(q1*(left-right-1)))
    else:
      ans=min(ans,left_s*l+right_s*r+(q2*(right-left-1)))
  return ans
  

n,l,r,q1,q2=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,l,r,q1,q2))
