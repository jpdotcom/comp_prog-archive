def main(a,b):
    
    return (pow(3,a,b)-1 )%b 

a,b=list(map(int,input().split()))
print(main(a,b)