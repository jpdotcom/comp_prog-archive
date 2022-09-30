import sys
import math
dp=[0]
mod=10**9+7
def pre():
    global dp
    for i in range(1,10**6+1):
        dp.append((i%mod*dp[-1]%mod+i%mod+dp[i-1]%mod)%mod)
pre()
def main(n):
    return dp[n]
    
    
for _ in range(int(input())):
    print(main(int(input())))

        