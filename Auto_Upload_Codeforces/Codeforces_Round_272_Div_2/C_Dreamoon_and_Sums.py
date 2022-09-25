

def main(a,b):
  mod=10**9+7
  a1=a%mod*b%mod*(b-1)%mod*pow(2,-1,mod)
  a2=(a%mod*(a+1)%mod*pow(2,-1,mod)*((b%mod)**2)*(b-1)%mod*pow(2,-1,mod))
  
  return int((a1+a2)%mod)
a,b=list(map(int,input().split()))


print(main(a,b))


