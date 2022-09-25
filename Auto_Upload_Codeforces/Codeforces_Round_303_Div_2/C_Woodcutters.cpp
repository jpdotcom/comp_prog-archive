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

using namespace std;




int func(int n, int arr[][2]){
    
    long int maxPoint=-2000000000;
    int ans=0;
    for (int i=0; i<n; i++){
        
        int start=arr[i][0];
        int dist=arr[i][1];
        if (i==n-1){
            
            ans++;
        }
        else if ((start-dist)>maxPoint){
            
            maxPoint=start;
            ans++;
        

        }
        else if ((start+dist)<arr[i+1][0]){
            
            maxPoint=start+dist;
            ans++;
        }
        else{
            maxPoint=start;
        }

    }
    cout<<ans;
    return 0 ;
}

int main()
{
   int n; 
   cin>>n;
   
   int arr[n][2];
   for (int i=0; i<n;i++){
       arr[i][0]=0;
       arr[i][1]=0;
       
   }
   
   for (int i=0;i<n;i++){
       cin>>arr[i][0];
       cin>>arr[i][1];
   }
 
    func(n,arr); 
    return 0;

}
