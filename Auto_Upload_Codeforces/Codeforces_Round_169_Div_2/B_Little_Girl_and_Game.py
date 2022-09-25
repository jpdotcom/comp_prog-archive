import math
import random 

def main(arr):
    cnt={}

    for e in arr:
        if e not in cnt:
            cnt[e]=0
        cnt[e]+=1 
    num_odd=0 
    for e in cnt:
        if cnt[e]&1:
            num_odd+=1 
    if num_odd&1 or num_odd==0:
        return 'First'
    return 'Second'

arr=input() 
print(main(arr)