import math

fac=[1]
mod=998244353
for i in range(1,5*10**5):
  val=(fac[-1]%mod*i%mod) 
  val%=mod 
  fac.append(val)


def nCr(a,b):
  second_val=(fac[a-b]*fac[b])
  return pow(fac[a],1,mod)*pow(second_val,-1,mod)
def main(arr):


  arr.sort()

  n=len(arr)
  if arr[-1]-arr[-2]>2:
    return 0 
  
  if arr[-1]-arr[-2]==0:
    return fac[n]
  
  less=0 
  max_val=arr[-1]
  for e in arr:
    if e+1==max_val:
      less+=1 
  ans=fac[n]
  for i in range(less,n):
    nums=n-i-1
    val=(nCr(n-less-1,nums)*fac[nums]*fac[i])%mod 

    ans-=val
  return ans%mod 

t=int(input())
ans=[]
for i in range(t):
  n=int(input())
  arr=list(map(int,input().split()))  
  s=main(arr)
 
  ans.append(s)
for e in ans:
  print(e)
