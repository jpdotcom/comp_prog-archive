
import math 
import sys
from decimal import Decimal
def main(arr,s):


  cnt={} 
  prefix=[arr[ord(s[0])-97]]

  for i in range(1,len(s)):
    prefix.append(prefix[-1]+arr[ord(s[i])-97])
  ans=0
  for i in range(0,len(s)):
    l=s[i] 
    val=prefix[i]
    sub=arr[ord(s[i])-97] 
    key=(val-sub,l)
    if key in cnt:
      ans+=cnt[key] 
    
    if (val,l) not in cnt:
      cnt[(val,l)]=0 
    cnt[(val,l)]+=1 
  
  return ans 

arr=list(map(int,input().split()))
s=input()
print(main(arr,s))
    

    






  
  
