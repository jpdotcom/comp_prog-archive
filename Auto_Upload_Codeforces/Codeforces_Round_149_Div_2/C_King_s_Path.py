from queue import Queue
def main(arr,start,end):

    points=set([])

    for i in range(len(arr)):
        row,x,y=arr[i]

        for j in range(x,y+1):
            points.add((row,j))
    
    dist={start:0}
    q=Queue(maxsize=0)
    q.put(start)
    while q.qsize()!=0:
        (x1,y1)=q.get()
        d=dist[(x1,y1)]
        if (x1,y1)==end:
            return dist[end]
        
        for i in range(-1,2):
            for j in range(-1,2):
                p=(x1+i,y1+j)
                if p not in dist and p in points:
                    dist[p]=1+d 
                    q.put(p) 
    
    return -1


a1,b1,a2,b2=list(map(int,input().split()))
start=(a1,b1)
end=(a2,b2)
n=int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))
print(main(arr,start,end))
                 

