import sys
import math
from queue import Queue 
import heapq

def main(s):
    
    freq={} 
    r='LTIME'
    for letter in s:
        if letter not in freq:
            freq[letter]=0
        freq[letter]+=1 
    for letter in r:
        if letter not in freq:
            return 'NO'
        if (freq[letter]>=2) or (len(s)==9 and letter=='E' and freq[letter]==1):
            continue 
        else:
            return 'NO'
    return 'YES'
    

t=int(input())
for i in range(t):
    s=input()
    print(main(s))