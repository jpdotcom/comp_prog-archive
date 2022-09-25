import math


def get_max(arr):
    
    ans1=None 
    ans2=float('inf')
    idx=0
    for e in arr:

      s_e=str(e)
      curr_d=0
      for i in range(len(s_e)-1,-1,-1):
        j=int(s_e[i])
        if j>0 and e!=1:
          if curr_d<ans2:
            ans2=curr_d  
            ans1=idx
        curr_d+=1 
          
      idx+=1
    return ans1,ans2
def main(s, n):
    s = str(s)
    nums = [0] * (n)

    j = 0

    for i in range(len(s)):
        val = int(s[i])
        while (val):
            e = nums[j]

            nums[j] = e + pow(10, len(s) - i - 1)
            val -= 1
            j += 1 
            j%=n


    nums.sort(reverse=True)
  
    curr_idx=len(nums)-1
    while nums[curr_idx]==0:

        max_idx,pos=get_max(nums)

        nums[max_idx] -= pow(10,pos)
        if nums[max_idx]==0:
          nums[max_idx] +=9*pow(10,pos-1)
          
        
          nums[curr_idx]+=pow(10,pos-1)
        else:
          nums[curr_idx]+=pow(10,pos)
        curr_idx-=1

    return nums


t = int(input())
ans = []
for i in range(t):
    s, n = list(map(int, input().split()))
    ans.append(main(s, n))
for e in ans:
    print(*e)
