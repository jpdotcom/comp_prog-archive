def main(s):
    
    s=[i for i in s]
    s.sort()
    s="".join(s)
    return s

t=int(input())
ans=[]
for i in range(t):
    s=input()
    ans.append(main(s))
for e in ans:
    print(e