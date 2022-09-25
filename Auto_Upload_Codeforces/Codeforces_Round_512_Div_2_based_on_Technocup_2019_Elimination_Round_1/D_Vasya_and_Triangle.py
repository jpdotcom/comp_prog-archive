
import math 
import sys
from decimal import Decimal
def isint(a):
  return int(a)==a
def main(n,m,k):




  
  
  
  f=[] 
  
  for i in range(1,int(math.sqrt(k))+1):
    a=i
    b=k/i 
    if b==int(b):
      f.append(int(b)) 
      f.append(a) 
  f.sort()
 
  l=0 
  r=len(f)-1 
 
  while l<=r:

    f1=f[l]
    f2=f[r]
    
    if (isint(2*m/f1) and isint(n/f2) and f1!=1):
      print('YES')
      print(0,0)
      print(0,2*m//f1)
      print(n//f2,0)
      return
    elif (isint(2*m/f2) and isint(n/f1) and f2!=1):
      print('YES')
      print(0,0)
      print(0,2*m//f2)
      print(n//f1,0)
      return
    elif ((isint(2*n/f1) and isint(m/f2) and f1!=1)):
      print('YES')
      print(0,0)
      print(2*n//f1,0)
      print(0,m//f2)
      return
    elif ((isint(2*n/f2) and isint(m/f1) and f2!=1)):
      print('YES')
      print(0,0)
      print(2*n//f2,0)
      print(0,m//f1)
      return
    l+=1 
    r-=1
  print("NO")
  return 
  
n,m,k=list(map(int,input().split()))
(main(n,m,k))





        


      
     