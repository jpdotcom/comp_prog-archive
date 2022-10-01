import sys
import math
def deterime_dist(rate,start,end,arr,ans):
    prev_start=start
    start=min(start,end)
    end=max(prev_start,end)
    
    ans+=(arr[end-1]-arr[start-1])*rate
    return ans
def main(A,B,C,D,P,Q,Y,arr):
    
    ##walk directly there
    ans1=0
    
    ans1=deterime_dist(P,A,B,arr,ans1)
    
    ## go to train(if possible)
    
    ans2=0
    ans2=deterime_dist(P,A,C,arr,ans2)
    if ans2>Y:
        ans2=float('inf')
    else:
        ans2=Y
    
    ans2=deterime_dist(Q,C,D,arr,ans2)
    
    ans2=deterime_dist(P,D,B,arr,ans2)
    
    return min(ans1,ans2)
    
for _ in range(int(input())):
    N,A,B,C,D,P,Q,Y=list(map(int,input().split()))
    
    arr=list(map(int,input().split()))
    print(main(A,B,C,D,P,Q,Y,arr))