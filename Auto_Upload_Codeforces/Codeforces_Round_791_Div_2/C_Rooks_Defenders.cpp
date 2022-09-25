#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
int query(int a,int b,int tree[], int n){
    a+=n;
    b+=n;
    int s=0;
    while (a<=b){
        if (a&1) s+=tree[a++];
        if ((b&1)==0) s+=tree[b--];
        a/=2,b/=2;
    }
    return s;
}
void update(int a,int tree[], int i, int n){
    i+=n;
    tree[i]=a;
    i>>=1;
    while (i>=1){
        tree[i]=tree[2*i]+tree[2*i+1];
        i>>=1;
    }
}
map<int,int> mpr;
map<int,int>mpc;
void solve(){
    int n,q; cin>>n>>q;
    int t1[2*n],t2[2*n];
    FOR(2*n) t1[i]=t2[i]=0;
    FOR(q){
        int v;cin>>v;
        if (v==1){
            int x,y;cin>>x>>y;
            if (mpr.find(x)==mpr.end()) mpr[x]=0;
            mpr[x]++;
            if (mpc.find(y)==mpc.end()) mpc[y]=0;
            mpc[y]++;
            update(1,t1,x,n);
            update(1,t2,y,n);
        }
        if (v==2){
            int x,y; cin>>x>>y;
            mpr[x]--;
            mpc[y]--;
            if (!mpr[x]) update(0,t1,x,n);
            if (!mpc[y]) update(0,t2,y,n);
        }
        if (v==3){
            int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
            if ((query(x1,x2,t1,n)==x2-x1+1) || query(y1,y2,t2,n)==y2-y1+1) print("Yes");
            else print("No");
        }
    }
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
