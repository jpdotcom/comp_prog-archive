#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
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
const int maxN=4e4+5;
int a[maxN];
void solve(){

    ll n; cin>>n;
    ll s=0;
    FOR(n){
        cin>>a[i];
        s+=a[i];
    }
    vector<ll> out;
    bool ok=true;
    if (s%(n*(n+1)/2)) ok=false;
    s/=(n*(n+1)/2);
    for (int i=0;i<n;i++){

        ll d=a[i]-a[((i-1)%n+n)%n];
        if ((s-d)%n) ok=false;
        if ((s-d)/n <= 0) ok=false;
        out.pb((s-d)/n);
    }
    if (ok){
        print("YES");
        FOR(n) cout<<out[i]<<' ';
        cout<<endl;
    }
    else print("NO"); 
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


