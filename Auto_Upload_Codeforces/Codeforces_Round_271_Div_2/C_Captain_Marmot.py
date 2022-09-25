import math
import heapq
def rotate(origin, point, angle):
    """
    Rotate a point counterclockwise by a given angle around a given origin.

    The angle should be given in radians.
    """
    ox, oy = origin
    px, py = point

    qx = ox + math.cos(angle) * (px - ox) - math.sin(angle) * (py - oy)
    qy = oy + math.sin(angle) * (px - ox) + math.cos(angle) * (py - oy)
    
    qx=round(qx)
    qy=round(qy)
    
    return (qx, qy)


def isright(distances):

  v1=distances[0] 
  v2=distances[1] 
  v3=distances[2]
 
  x1,y1=p1=v1[1] 
  x2,y2=p2=v1[2]
  x3,y3=p3=v2[2]
  x4,y4=p4=v3[2]
  if (x2-x1)*(x3-x1)+(y3-y1)*(y2-y1)==0:
    
    if (x2-x4)*(x3-x4)+(y3-y4)*(y2-y4)==0:
      
      return True
  return False
  
def dist(p1,p2):
  x1,y1=p1 
  x2,y2=p2 
  return (x2-x1)**2+(y2-y1)**2
def main(arr):


  for i in range(len(arr)):
    
    points=arr[i] 
    
    
    ans=float('inf')
    for a in range(4):
      for b in range(4):
        for c in range(4):
          for d in range(4):
            p1=points[0][0]
            p1_r=points[0][1] 
            
            p2=points[1][0] 
            p2_r=points[1][1]
            
            p3=points[2][0]
            p3_r=points[2][1]
            
            p4=points[3][0] 
            p4_r=points[3][1] 
            val=math.pi/2
            p1=rotate(p1_r,p1,a*val)
            p2=rotate(p2_r,p2,b*val)
            p3=rotate(p3_r,p3,c*val)
            p4=rotate(p4_r,p4,d*val)
            new_points=set([p1,p2,p3,p4])
            if len(new_points)==4:

              d1=(dist(p1,p2),p1,p2)
              d2=(dist(p1,p3),p1,p3)
              d3=(dist(p1,p4),p1,p4) 
              distances=[d1,d2,d3] 
              
              distances.sort(key=lambda x:x[0]) 
              if isright(distances) and distances[0][0]==distances[1][0] and distances[1][0]*2==distances[2][0] and distances[0][0]!=0:
                
                ans=min(a+b+c+d,ans)
    if ans==float('inf'):
      print(-1) 
    else:
      print(ans) 
  return 

n=int(input())
arr=[]
for i in range(n):
  temp=[] 
  for j in range(4):
    a=list(map(int,input().split()))
    a1=tuple(a[:2])
    a2=tuple(a[2:])
    temp.append([a1,a2])
  arr.append(temp)
(main(arr))

 
 
 
 
 
 
 
 
 
 
 
