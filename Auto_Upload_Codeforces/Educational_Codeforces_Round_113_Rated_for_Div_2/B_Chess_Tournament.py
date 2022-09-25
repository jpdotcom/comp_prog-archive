import math


def main(arr):


  ans=[[0 for i in range(len(arr))] for j in range(len(arr))]
  won=[False]*(len(arr))
  for i in range(len(arr)):
    for j in range(i,len(arr)):
      if i==j:
        ans[i][j]='X'
        ans[j][i]="X"
      elif (arr[i]==1 or arr[j]==1):
        ans[i][j]='='
        ans[j][i]='='
      else:
        if (not won[i]):
          ans[i][j]='+'
          ans[j][i]='-'
          won[i]=True
        else:
          ans[i][j]='-'
          ans[j][i]='+'
          won[j]=True
 
  for i in range(len(won)):
    if arr[i]==2 and not won[i]:
      return ["NO"]
  return ['YES',ans] 
t=int(input())
ans=[]
for i in range(t):
  n=int(input())
  ans.append(main([int(c) for c in input()]))

for e in ans:
  i=0
  for p in e:
    if i==0:
      print(p)
    else:
      for c in p:

        print("".join(c))
    i+=1

