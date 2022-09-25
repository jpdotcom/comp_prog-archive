import math
def main(arr,a):


  f=[] 

  for i in range(1,int(math.sqrt(a))+1):
    
    f1=i 
    f2=a/i 
    if f2==int(f2):
      f.append(f1)
      if f2!=f1:
        f.append(int(f2))
  f.sort()
  
  
  prefix=[0] 
  
  for i in range(len(arr)):
    prefix.append(prefix[-1]+arr[i])
  
  diff={} 
 
  for i in range(len(prefix)):
    for j in range(0,i):
      val= prefix[i]-prefix[j]
      if val not in diff:
        diff[val]=0 
      diff[val]+=1 
  if a==0:
    for e in diff:
      f.append(e) 
      f.append(0)
    f.sort()
  ans=0
  i=0 
  j=len(f)-1 
  
  while i<=j:
    f1=f[i] 
    f2=f[j]
    
    if f1 in diff and f2 in diff:
      if f1==f2:
        ans+=diff[f1]*diff[f2]
      else:

        ans+=2*(diff[f1]*diff[f2])
    i+=1 
    j-=1
  return ans 

    
  

a=int(input())
arr=[int(c) for c in input()]
print(main(arr,a)) 