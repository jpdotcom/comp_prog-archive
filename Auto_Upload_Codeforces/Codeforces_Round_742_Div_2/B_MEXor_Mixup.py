precomp=[]
ans=0
for i in range(0,3*10**5+1):
  
  ans^=i 
  precomp.append(ans)

def main(a,b):
  if precomp[a-1]==b:
    return a
  
  if precomp[a-1]^b==a:
    return a+2 
  else:
    return a+1  
  
t=int(input())
ans=[]
for i in range(t):
  a,b=list(map(int,input().split()))
  ans.append(main(a,b)) 
for e in ans:
  print(e)
  


    
    



