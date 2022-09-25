def main(m,s):


  
  s_copy=s 

  ans=[]
  while (s_copy):
    ans.append(min(s_copy,9)) 
    s_copy-=ans[-1] 
  if len(ans)>m or (len(ans)==1 and ans[0]==0):
    print('-1','-1') 
    return 
  ans+=[0]*(m-len(ans))
  
  ans2= [0]*(m)
  ans2[0]=1 if m!=1 else 0
  if (s<1 and m!=1):
    print('-1','-1')
    return
  i=m-1 
  while s and i>=0:
    sub=1 if i!=0 else 0
    ans2[i]=min(s-sub,9) 

    s-=ans2[i]
   
    i-=1
 
  if s>0 :
    print('-1','-1') 
    return
  
  ans="".join([str(c) for c in ans])
  ans2="".join([str(c) for c in ans2])
  print(ans2,ans)
  return 

n,m=list(map(int,input().split()))
main(n,m)




