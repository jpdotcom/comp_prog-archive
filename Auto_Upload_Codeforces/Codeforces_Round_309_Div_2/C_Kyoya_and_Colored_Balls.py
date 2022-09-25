mod=10**9+7
fac=[1]
for i in range(1,2000):
  val=fac[-1]*i
  val%=mod
  fac.append(val)
def nCr(a,b):

  val1=fac[a] 
  val2=fac[a-b]*fac[b] 

  return (fac[a]*pow(val2,-1,mod))%mod
def main(arr):


  ans=1
  l=0
  
  for e in arr:
    l+=e 

    ans*=nCr(l-1,e-1) 
   
    ans%=mod 
  return ans 

k=int(input())
arr=[]
for i in range(k):
  arr.append(int(input()))

print(main(arr)