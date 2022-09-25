def main(s):
    
    a=0 
    d=0 
    for e in s:
        if e=="A":
            a+=1 
        else:
            d+=1 
    if a>d:
        print('Anton') 
    elif d>a:
        print('Danik')
    else: 
        print('Friendship')
    return 
n=int(input())
s=input() 
main(s