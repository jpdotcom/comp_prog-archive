import math 
import heapq
def main(arr,k):



  end=max(abs(sum([x for x in arr if x>0])),abs(sum([x for x in arr if x<0])))

  start=1 
  prefix=[arr[0]]
  cnt={} 
  
  for i in range(1,len(arr)):
    val=arr[i]+prefix[-1] 
    prefix.append(val)
    
  ans=0
  while start<=end:
    
    cnt={} 
    
    for i in range(len(prefix)):
      
      if prefix[i]-start in cnt:
      
        ans+=cnt[prefix[i]-start] 
      if prefix[i]==start:
        ans+=1
      if prefix[i] not in cnt:
        cnt[prefix[i]]=0 
      
      cnt[prefix[i]]+=1 
      
    if k==1:
      start=end+1
    elif k==-1:
      if start==1:
        start=-1 
      else:
        break
    else:

      start*=k 
    
  return ans
n,k=list(map(int,input().split()))
arr=list(map(int,input().split()))
print(main(arr,k))
