#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip> 
using namespace std;




float func(float x[],float y[],float z[],int n,int m, int k,float a, float b){
    

    float c=a/b;
    float r2=0.0;
    sort(x,x+n);
    sort(y,y+m);
    sort(z,z+k);


    float r1=x[n-1];
    float p1=y[m-1];
    float p2=z[0];
    
    float q=sqrt((r1*r1*p1)/(p2*c+p1));
                
                
                
                
                
    cout<<setprecision(8)<<q;
    return 0 ;
    
}
    
    



int main()
{
   int n; 
   int m;
   float a;
   float b;
   int k;
   cin>>n;
   
   float x[n]={0};

   
   
   for (int i=0;i<n;i++){
       cin>>x[i];
   }
    cin>>m;

    float y[m]={0};
    for (int i=0;i<m;i++){
        cin>>y[i];
    }

    cin>>k;

    float z[k]={0};
    for (int i=0;i<k;i++){
        cin>>z[i];
    }
    cin>>a;
    cin>>b;
    func(x,y,z,n,m,k,a,b);
    return 0;

}
