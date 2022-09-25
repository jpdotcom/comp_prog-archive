def main(a,b):
    
    for i in range(len(a)):
        
        e1=a[i].lower() 
        e2=b[i].lower() 
        
        if ord(e1)<ord(e2):
            print('-1') 
            return
        elif ord(e1)>ord(e2):
            print('1')
            return 
    print('0')
    return 
 
a=input()
b=input()
main(a,b