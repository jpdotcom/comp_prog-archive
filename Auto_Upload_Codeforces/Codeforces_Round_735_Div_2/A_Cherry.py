def main(arr):
  ans=0 
  for i in range(len(arr)-1):
    ans=max(ans,arr[i]*arr[i+1])
  return ans 
ans=[]
for i in range(int(input())):
  n=int(input())
  ans.append(main(list(map(int,input().split()))))
for e in ans:
  print(e