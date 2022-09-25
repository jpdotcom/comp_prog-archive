def main(n):


  vals=[0,0]
  idx=0
  l=0
  while (n):
    
    
    
    
    d=n%10 

    vals[idx]+=d*pow(10,l) 
    n//=10 
    idx^=1 
    if (idx==0):
      l+=1
  
  if vals[0]==0 or vals[1]==0: 
    return max(vals)-1 
  else:
    return (vals[0]+1)*(vals[1]+1)-2

t=int(input())
ans=[]
for i in range(t):
  ans.append(main(int(input())))

for e in ans:
  print(e)


   