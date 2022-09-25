import math


def main(arr):





  for i in range(len(arr)):
    a_cnt,b_cnt=0,0 
    for j in range(i,len(arr)):

      if arr[j]=='a':
        a_cnt+=1 
      else:
        b_cnt+=1 
      if a_cnt==b_cnt:
        return [i+1,j+1]
  return [-1,-1]

t=int(input())
ans=[]
for i in range(t):
  n=int(input())
  ans.append(main(input()))
for e in ans:
  print(*e)
