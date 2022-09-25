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
    return res;
}
long long inf=pow(10,18)+1;
int col(double m1, double c1,pair<int,int>p1){
    int x,y;
    x=p1.first;
    y=p1.second;
    return (y==m1*x+c1);
    }

int find_max(int a, int b, int t[],int n){
    a+=n;
    b+=n;
    int s=0;
    while (a<=b){
        if (a%2==1) s=max(s,t[a++]);
        if (b%2==0) s=max(s,t[b--]);
        a/=2; b/=2;}
    
    return s;}
void update(int k, int x, int t[],int n){
    
    k+=n;
    
    t[k]=max(t[k],x);
    for (k/=2;k>=1;k/=2){
        t[k]=max(t[2*k],t[2*k+1]);}
    
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];}}
    int tree[m][2*n];
    for (int i=0;i<m;i++){
        for (int j=0;j<2*n;j++){
            
            tree[i][j]=0;}}

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            update(j,arr[j][i],tree[i],n);
            
            
        }}
    
    int best_idx=-1;
    int max_len=0;
    for (int i=0;i<n;i++){
        
        int best=-1;
        int l,r;
        l=i;
        r=n-1;
        while (l<=r){
            int val=0;
            int mid=l+(r-l)/2;
            for (int j=0;j<m;j++){
                int add=0;
                
                add=find_max(i,mid,tree[j],n);
                val+=add;
                }
            
            if (val==k){
                best=mid;
                l=mid+1;}
            else if (val>k){
                r=mid-1;}
            else{
                l=mid+1;
                best=mid;}
            }
        
        if ((best-i+1)>max_len){
            best_idx=i;
            max_len=best-i+1;
            }}
    if (best_idx==-1){
        for (int j=0;j<m;j++){
            cout<<0<<' ';}}
    else{ 
        for (int j=0;j<m;j++){
            cout<<find_max(best_idx,best_idx+max_len-1,tree[j],n)<<' ';
            }}
    return 0;}



