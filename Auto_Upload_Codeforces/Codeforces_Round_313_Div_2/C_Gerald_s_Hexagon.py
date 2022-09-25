import math
import random 
from queue import Queue
import time 



def main(lengths):
  
  area_triangle=0
  ans=0
  sides=[]
  for i in range(0,6,2):
    
    v1=lengths[i]
    v2=lengths[i+1]

    ans+=(v1*v2) 
    sides.append(math.sqrt(v1**2+v2**2+v1*v2))
 
  s=sum(sides)/2 

  area_triangle=math.sqrt(s*(s-sides[0])*(s-sides[1])*(s-sides[2]))
  
  ans+=area_triangle/(math.sqrt(3)/4)
  return round(ans)
lengths=list(map(int,input().split()))
print(main(lengths))
  
  

   