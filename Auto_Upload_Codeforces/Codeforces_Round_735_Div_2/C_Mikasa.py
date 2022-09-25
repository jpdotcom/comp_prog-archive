import math


def main(n,m):

  if n>m:
    return 0 

  n=[c for c in bin(n)[2:]]
  m=[c for c in bin(m)[2:]]

  n=['0']*(len(m)-len(n))+n


  ans=0
  valid=False

  for i in range(len(n)):
  
    if n[i]=='1' and m[i]=='0':

      
      valid=True
    
      break
    else:
      
      xor=int(n[i])^int(m[i])
      if xor:
        ans+=pow(2,len(n)-i-1)
  if valid:
    return ans
  ans=0
  idx=None
  for i in range(len(n)-1,-1,-1):

    if m[i]=='0':
      m[i]='1'
      idx=i 
      break 
  if idx!=None:
 
    for i in range(0,idx+1):
      xor=int(n[i])^int(m[i])
      if xor:
        ans+=pow(2,len(n)-i-1)
    return ans

  s=int(math.log2(int("".join(m),2)))+1
  return 2**s 

ans=[] 
for i in range(int(input())):
  try:
    n,m=list(map(int,input().split()))
    ans.append(main(n,m))
  except Exception as e: print(e)

for e in ans:
  print(e