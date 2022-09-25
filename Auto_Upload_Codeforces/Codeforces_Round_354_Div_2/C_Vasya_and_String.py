
import math 
import sys
def main(s,k):


  count_a=[] 
  count_b=[]

  for i in range(len(s)):

    if i==0:
      if s[i]=='a':
        count_a.append(1)
        count_b.append(0)
      else:
        count_a.append(0)
        count_b.append(1) 

    elif s[i]=='b':
      count_a.append(count_a[-1])
      count_b.append(count_b[-1]+1)
    else:
      count_a.append(count_a[-1]+1) 
      count_b.append(count_b[-1])
  
  ans=0
  for i in range(len(s)):

    l=i 
    r=len(s)-1 
    best=-1 

    while l<=r:

      m=(l+r)//2
      if i==0:
        l_val=0 
      else:
        l_val=count_a[i-1]
      val_a=count_a[m]-l_val 
      if val_a==k:
        l=m+1 
        best=m 
      elif val_a<k:
        l=m+1 
        best=m 
      else:
        r=m-1 
    if best!=-1:
      ans=max(ans,best-i+1) 
    
    l=i 
    r=len(s)-1 
    best=-1 

    while l<=r:

      m=(l+r)//2
      if i==0:
        l_val=0 
      else:
        l_val=count_b[i-1]
      val_b=count_b[m]-l_val 
      if val_b==k:
        l=m+1 
        best=m 
      elif val_b<k:
        l=m+1 
        best=m 
      else:
        r=m-1 
    
    if best!=-1:
      ans=max(ans,best-i+1) 
  return ans
      
    

     
n,k=list(map(int,input().split()))
s=input()
print(main(s,k))
  
    
      
     