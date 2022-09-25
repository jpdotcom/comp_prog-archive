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
#define FOR(a,b) for (int i=a;i<b;++i)
using namespace std;
int mod(int a,int b){
    return (b+(a%b)) % b;}
int power(long long x, unsigned int y, int p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;}


long long dist[301][301];

int main(){
    
    int n;
    cin>>n;
    long long last_s=0;
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            int b;
            cin>>b;
            
            dist[i][j]=b;
            last_s+=b;
            
        }
            
    }
    last_s/=2;

    int k;

    cin>>k;
    vector<long long>ans;
    for (int i=0;i<k;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        if (c<dist[a][b]){
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
        vector<long long>update;
        update.push_back(a);
        update.push_back(b);
        for (int j=0;j<2;j++){
            long long o=update[j];
            for (int l=1;l<n+1;l++){
                for (int m=1;m<n+1;m++){
                    
                    dist[l][m]=min(dist[l][m],dist[l][o]+dist[o][m]);
                }}}
        long long s=0;
        for (int j=1;j<n+1;j++){
            for (int l=j+1;l<n+1;l++){
            
                s+=dist[j][l];}
            }
        last_s=s;
        ans.push_back(s);}
        else{
            ans.push_back(last_s);}


    


}   
    for (long long v:ans){
        cout<<v<<' ';}
    return 0;}
