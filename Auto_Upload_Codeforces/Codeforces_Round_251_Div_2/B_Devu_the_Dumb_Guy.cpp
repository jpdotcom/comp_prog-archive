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




int func(long long arr[],int n,int l){
    

    unsigned long long ans=0;
    sort(arr,arr+n);
    for (int i=0;i<n;i++){
        unsigned long long add=arr[i]*l;
        ans+=add;
        l=max(l-1,1);

    }
    cout<<fixed<<setprecision(0)<<ans;
    return 0 ;



}
    
    



int main()
{
    int n;
    int l;
    cin>>n; 
    cin>>l;
    long long arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    func(arr,n,l);


}
