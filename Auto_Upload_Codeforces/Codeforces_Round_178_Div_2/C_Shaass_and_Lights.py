import math

facs=[1] 
mod=10**9+7
for i in range(1,2000):
  facs.append((facs[-1]*i)%mod)
def nCr(a,b):
  
  val1=facs[a]
  val2=pow(facs[b]*facs[a-b],-1,mod)
  return (val1*val2)%mod
def main(n,m): 

  lens=[] 

  l=0 

  for i in range(1,n+1):
    if i in m:
      lens.append(l) 
      l=0 
    else:
      l+=1
  lens.append(l) 
  
  ans=1 
  t=n-len(m)

  for i in range(len(lens)):

    l=lens[i] 

    if i!=0 and i!=len(lens)-1 and l!=0:
      ans*=pow(2,(l-1),mod)
    ans%=mod
    
    ans*=nCr(t,l)
    ans%=mod
    t-=l
  return int(ans)  

n,m=list(map(int,input().split()))
arr=set(list(map(int,input().split())))
print(main(n,arr))

