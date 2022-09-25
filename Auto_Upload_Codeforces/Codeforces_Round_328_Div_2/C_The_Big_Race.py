import math 
import heapq
def lcm(a, b):
    return abs(a*b) // math.gcd(a, b)
def main(t,a,b):
  if a==b:
    print("1/1")
    return
  val=lcm(a,b)
 
  nums=t//val 
 
  ans1=nums*min(a,b)-1
  
  ans1+=min(t-val*nums+1,min(a,b))
  
  ans2=t 

  g=math.gcd(ans1,ans2) 
  ans1//=g 
  ans2//=g 
  print(str(ans1)+"/"+str(ans2))
  return


t,a,b=list(map(int,input().split()))
main(t,a,b)
