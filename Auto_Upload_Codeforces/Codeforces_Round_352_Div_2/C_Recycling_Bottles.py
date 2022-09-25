import math 


def getdist(x,y,a,c):
  return math.sqrt((x-a)**2+(c-y)**2)
def main(n,points,start):

  x1,y1=start[0],start[1]
  x2,y2=start[2],start[3]
  x3,y3=start[4],start[5]
  
  dist=[] 
  dist_p1=[] 
  dist_p2=[]
  for i in range(len(points)):
    x4,y4=points[i]
    
    dist.append(getdist(x4,y4,x3,y3))
    dist_p1.append((i,getdist(x4,y4,x1,y1)-dist[i]))
    dist_p2.append((i,getdist(x4,y4,x2,y2)-dist[i]))
  dist_p2.sort(key=lambda x:x[1])
  dist_p1.sort(key=lambda x:x[1])
  val1=dist_p2[0] 
 
  if len(dist_p2)>1:
    val2=dist_p2[1]
  else:
    val2=(None,float('inf'))
  
  sum_dist=sum(dist) 
  ans=float('inf')
  for i in range(len(dist_p1)):
    
    i1,d1=dist_p1[i]

    i2,d2=val1 
    i3,d3=val2 
    
    if i1!=i2:
      ans=min(ans,d1+d2+2*sum_dist)
    elif i3!=None:
      ans=min(ans,d1+d3+2*sum_dist)
  i1,d1=dist_p1[0] 
  i2,d2=val1 
  ans=min(ans,d1+2*sum_dist)
  ans=min(ans,d2+2*sum_dist)
  return ans


start=list(map(int,input().split()))
n=int(input())
arr=[] 
for i in range(n):
  arr.append(list(map(int,input().split())))
print(main(n,arr,start))
