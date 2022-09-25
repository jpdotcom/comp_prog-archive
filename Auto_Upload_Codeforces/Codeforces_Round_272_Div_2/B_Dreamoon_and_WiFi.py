import math

def main(s1,s2):

  d={"+":1,"-":-1}
  
  t=0
  for i in range(len(s1)):
    
    t+=d[s1[i]]
  q=0
  
  for j in range(len(s2)):
    
    if s2[j] in d:
    
      t+=((-1)*d[s2[j]])
      
    else:
      q+=1
  
  if  t==0 and q==0:
    return 1
  pos=(q+t)/2 
  neg=(q-t)/2 
  if pos!=int(pos) or neg!=int(neg) or neg<0 or pos<0:
    return 0 
  else:
    return math.comb(q,int(pos))/(2**q)
a=input()
b=input()
print(main(a,b))




