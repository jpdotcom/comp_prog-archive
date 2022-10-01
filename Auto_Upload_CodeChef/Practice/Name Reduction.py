import sys
import math

def main(arr,parents):
    
    freq={}
    freq_parent={}
    for name in arr:
        for letter in name:
            if letter not in freq:
                freq[letter]=0 
            freq[letter]+=1 
    for name in parents:
        
        for letter in name:
            if letter not in freq_parent:
                freq_parent[letter]=0 
            freq_parent[letter]+=1 
   
    for letter in freq:
        if letter not in freq_parent or freq_parent[letter]<freq[letter]:
            return "NO"
    return 'YES'


t=int(input())

for i in range(t):
    parents=input().split()
    n=int(input())
    arr=[]
    for j in range(n):
        arr.append(input().split()[0])
    print(main(arr,parents))
        
        

        