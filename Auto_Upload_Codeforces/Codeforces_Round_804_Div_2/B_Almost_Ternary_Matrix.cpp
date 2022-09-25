#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=51;
int a[maxN][2];
void p(int idx, int m){
    for (int i=0;i<m;i++) cout<<a[i][idx]<<' ';
    cout<<endl;
}
void get(int n,int m){
    int c=0,v=1;
    p(0,m);
    for (int i=1;i<n;i++){
        if (c==2){
            v^=1;
            c=0;
        }
        p(v,m);
        c++;
    }
}
void solve(){
    int n,m; cin>>n>>m;
    a[0][0]=0;
    int c=0,v=1;
    FOR(m-1){
        if (c==2){
            c=0;
            v^=1;
        }
        a[i+1][0]=v;
        c++;
    }
    a[0][1]=1;
    v=0,c=0;
    FOR(m-1){
        if (c==2){
            c=0;
            v^=1;
        }
        a[i+1][1]=v;
        c++;
    }
    get(n,m);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
