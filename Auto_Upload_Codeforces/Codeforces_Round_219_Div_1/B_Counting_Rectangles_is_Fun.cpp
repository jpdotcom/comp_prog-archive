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
#define FOR(a,b) for (int i=a;i<b;++i)
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first
#define S second
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
ll root(ll x) {
ll l = 0, r = 1e9 + 1;
while (l < r - 1) {
ll m = (l + r) / 2;
if (m * m > x)
r = m;
else
l = m;
}
return l;
}
int power(long long x, unsigned int y, ll p)
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
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
const int maxN=45;
int table[maxN][maxN];
int prefix[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];
int get_sum(int a, int b, int c, int d){
    int ans=prefix[c][d];
    if (a!=0 && b!=0){
        ans+=prefix[a-1][b-1];
    }
    if (a!=0){
        ans-=prefix[a-1][d];
    }
    if (b!=0){
        ans-=prefix[c][b-1];
    }
    return ans;
}

int inter(vector<array<int,4>> c){
    int i,j,k,l;
    i=-1;
    j=-1;
    k=maxN;
    l=maxN;
    for (unsigned int idx=0;idx<c.size();idx++){
        
        i=max(i,c[idx][0]);
        j=max(j,c[idx][1]);
        k=min(k,c[idx][2]);
        l=min(l,c[idx][3]);
        if (i>k||j>l){
            return 0;
        }
    }
    
    return dp[i][j][k][l];
}
int un(vector<array<int,4>> c){
    if (c.size()==0){
        return 0;
    }
    int total=pow(2,c.size())-1;
    int ans=0;
    for (int i=1;i<=total;i++){
        int mult=-1;
        vector<array<int,4>>c2;
        for (unsigned int j=0;j<c.size();j++){
            if ((i>>j)%2){
                mult*=-1;
                c2.push_back(c[j]);
            }
        }
        ans+=mult*inter(c2);
    }
    return ans;


}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=0;i<n+1;i++){
        string s;
        getline(cin,s);
        if (i==0){
            continue;
        }
        else{
        for (int j=0;j<m;j++){
            int a= ((int) s[j]) - 48;
            table[i-1][j]=a;

            prefix[i-1][j]=table[i-1][j];
            if (i!=1){
                prefix[i-1][j]+=prefix[i-2][j];
            }
            if (j!=0){
                prefix[i-1][j]+=prefix[i-1][j-1];
            }
            if (i!=1 && j!=0){
                prefix[i-1][j]-=prefix[i-2][j-1];
            }
        }
        }
    }
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            for (int k=i;k<n;k++){
                for (int l=j;l<m;l++){
                    dp[i][j][k][l]=0;
                    vector<array<int,4>> comp;
                    if (i!=k){
                       if (i!=n-1){
                        array<int,4> arr;
                        arr[0]=i+1;
                        arr[1]=j;
                        arr[2]=k;
                        arr[3]=l;
                        comp.push_back(arr);
                        }
                        if(k>0){
                            array<int,4>arr2;
                        arr2[0]=i;
                        arr2[1]=j;
                        arr2[2]=k-1;
                        arr2[3]=l;
                        comp.push_back(arr2);
                        }
                    }
                    if (j!=l){
                        if (j!=m-1){
                        array<int,4>arr3;
                        arr3[0]=i;
                        arr3[1]=j+1;
                        arr3[2]=k;
                        arr3[3]=l;
                        comp.push_back(arr3);
                        }
                        if (l!=0){
                        array<int,4>arr4;
                        arr4[0]=i;
                        arr4[1]=j;
                        arr4[2]=k;
                        arr4[3]=l-1;
                        comp.push_back(arr4);
                        }
                    }
                    dp[i][j][k][l]=(get_sum(i,j,k,l)==0)+un(comp);

                }
            }
        }
    }
    vector<int>out;
    for (int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--,b--,c--,d--;
        out.push_back(dp[a][b][c][d]);
        
    }
    for (int x:out){
        cout<<x<<endl;
    }
    return;
}

void precompute(){
}


int main(){
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

