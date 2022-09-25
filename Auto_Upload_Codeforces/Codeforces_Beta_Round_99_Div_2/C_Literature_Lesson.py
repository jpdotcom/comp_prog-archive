def rhyme(a,b,k):
  v=["a","e","i","o","u"]
  i_a=None
  i_b=None
  v_a=0
  v_b=0
  for i in range(len(a)-1,-1,-1):
    if a[i] in v:
      v_a+=1 
    if v_a==k:
      i_a=i 
      break 
  for i in range(len(b)-1,-1,-1):
    if b[i] in v:
      v_b+=1 
    if v_b==k:
      i_b=i 
      break
  
  if i_a!=None and i_b != None and a[i_a:]==b[i_b:]:
    
    return True 
  return False

def main(arr,k):
  style={0:"aabb",1:"abab",2:"abba",3:'aaaa'}
  ans=[]
  for j in range(4):
    c=True
   
    for i in range(len(arr)):
      q=arr[i]
      if j==0:
        if rhyme(q[0],q[1],k) and rhyme(q[2],q[3],k):
          continue 
        else:
          c=False
          break 
      if j==1: 
        if rhyme(q[0],q[2],k) and rhyme(q[1],q[3],k):
          continue 
        else:
          c=False
          break 
      if j==2:
        if rhyme(q[0],q[3],k) and rhyme(q[1],q[2],k):
          continue 
        else:
          c=False
          break
      if j==3:
        
        if rhyme(q[0],q[1],k) and rhyme(q[1],q[2],k) and rhyme(q[2],q[3],k):
          continue 
        else:
          c=False
          break
      
    if c:
      
      ans.append(j)
 
  if 3 in ans:
    return style[3]
  elif len(ans)>=1:
    return style[ans[0]]
  else:

    return "NO"

n,k=list(map(int,input().split()))
arr=[] 

for i in range(n):
  temp=[]
  for j in range(4):
    temp.append(input())
  arr.append(temp)
print(main(arr,k))
    




