def main(n):



  if n==1:
    return 'a'
  
  if n%2:
    mid=['b','c']
    n-=2 
  else:
    mid=['b']
    n-=1
  
  k=(n+1)//2 
  pt1=['a']*k 
  pt2=['a']*(k-1) 
  
  ans="".join(pt1+mid+pt2) 
  return ans 
ans=[]
for i in range(int(input())):
  ans.append(main(int(input())))
for e in ans:
  print(e)
