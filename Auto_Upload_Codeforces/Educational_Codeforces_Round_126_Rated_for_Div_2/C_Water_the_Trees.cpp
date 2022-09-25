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
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=3e5+1;
int ar[maxN];
void solve(){
    int n;
    cin>>n;
    int ma=0;
    FOR(n){
        cin>>ar[i];
        ma=max(ar[i],ma);
    }
    sort(ar,ar+n);
    ll ans=1e15;
    ll v[2]={ma,ma+1};
    for (int x: v){

        ll l=0,r=1e15;
    while (l<=r){
        ll m=l+(r-l)/2;
        ll a=ceil(m/(2.0)),b=m-a;
        bool ok=true;
        FOR(n){
            ll d=x-ar[i];
                ll s=min(d/2,b);
                b-=s;
                d-=2*s;
                ll t=min(a,d);
                a-=t;
                d-=t;
                if (d!=0) ok=false;
        }
        if (ok) {
            ans=min(ans,m);
            r=m-1;
        }
        else l=m+1;
    }
    }
    print(ans);
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
