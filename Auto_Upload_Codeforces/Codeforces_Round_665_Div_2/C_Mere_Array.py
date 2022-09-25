import math
def main(arr):
    
    
    
    s=sorted(arr) 
    m=s[0] 
    g=0
    for i in range(len(s)):
        if s[i]!=arr[i]:
            
            g=math.gcd(g,arr[i]) 
    
    if math.gcd(g,m)==m:
        return 'YES' 
    return 'NO'
    
    
t=int(input())
ans=[]
for i in range(t):
    n=int(input())
    ans.append(main(list(map(int,input().split()))) )

for e in ans:
    print(e