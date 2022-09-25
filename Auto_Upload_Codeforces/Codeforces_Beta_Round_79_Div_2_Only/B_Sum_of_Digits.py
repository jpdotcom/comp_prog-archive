import math
def s(a):
    ans=0
    for e in a:
        ans+=int(e)
    return str(ans)
def main(a):
    if int(a)<=9:
        return 0
    return 1+main(s(a))
    
 
a=input()
print(main(a)