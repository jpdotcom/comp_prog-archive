import math
def main(arr1,arr2):

    k=0
    curr=0
    q=0
    for e in arr1:
        if e=="+":
            k+=1 
        else:
            k-=1 
    for e in arr2:
        if e=='+':
            curr+=1 
        elif e=='-':
            curr-=1
        else:
            q+=1 
    k-=curr
    
    x=(k+q)/2
    
    if x>=0 and x==int(x):
        x=int(x)
    else:
        return 0
    ans=(1/2**q)*math.comb(q,x)
    return ans
a=[c for c in input()]
b=[c for c in input()]
print(main(a,b)