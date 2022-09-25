def main(n,a,b,c,d):
    
    
    s=[a+b,b+d,d+c,c+a]
    s.sort() 
    a,b,c,d=s 
    ans=n*max(0,n+a-d)
       
                   
                 
    return ans

n,a,b,c,d=list(map(int,input().split()))
print(main(n,a,b,c,d)