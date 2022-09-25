import math
import random 


  

def main(n):
    arr1=[x for x in range(n)] 
    if n%2==0:
       print(-1)
       return
    arr2=list(reversed(arr1))
    arr3=[]
    for i in range(len(arr1)):
        if arr2[i]>=arr1[i]:

            arr3.append(arr2[i]-arr1[i])
        else:
            arr3.append(n+arr2[i]-arr1[i])
    
    print(*arr1) 
    print(*arr3) 
    print(*arr2) 
    return 

n=int(input())
main(n)

                

    



    

