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
#include <cmath>
using namespace std;
typedef long long LL;

void func(){
    int n;
    int t;
    cin>>n; 
    cin>>t;
    
    int arr[n]={0};
    int min_abs=pow(2,31)-1;
    int idx=true;
    sort(arr,arr+n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
        
        if (min_abs>abs(arr[i])){
            idx=i;
            min_abs=abs(arr[i]);
        }
    }
 
    int i=0;
    while (t>0 & arr[i]<0 &i<(n-1)){
        arr[i]=-1*arr[i];
        t--;
        i++;
    }
    
    arr[idx]=pow(-1,t)*arr[idx];
    
    
    int sum=0;
    for (int i=0; i<n; i++){
        
        sum=sum+arr[i];
    }
    cout<<sum;

}
    
int main()
{
    func();
    return 0;
    
    


}
