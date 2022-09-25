import math

def main(a,b):


  a_1=0 
  b_1=0

  for e in b:
    if int(e) :
      b_1+=1 
  for e in a:
    if int(e):
      a_1+=1 
  if a_1%2==1:
    a_1+=1
  if a_1>=b_1:
    return "YES"
  return "NO"

a=input() 
b=input()
print(main(a,b))
