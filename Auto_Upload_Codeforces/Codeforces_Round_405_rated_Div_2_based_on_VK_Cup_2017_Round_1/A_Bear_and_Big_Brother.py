import math
def main(a,b):
    
    ans=math.log10(b/a)/math.log10(3/2)
    print(int(ans)+1)
    return 
 
a,b=list(map(int,input().split()))
main(a,b