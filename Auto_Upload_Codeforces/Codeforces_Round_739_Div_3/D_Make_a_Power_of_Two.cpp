#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD 1e9+7;
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
void solve(){
    string s;
    cin>>s;
    int ans=s.size()+1;
    ll end=pow((ll)2,57);
    for (ll i=1;i<=end;i*=2){
        string m=to_string(i);
        int idx=0;
        for (int j=0;j<(int)s.size();j++){
            idx+=((idx<(int)m.size() && m[idx]==s[j]) ? 1 : 0);
        }
        ans=min(ans,(int)s.size()-idx+(int)m.size()-idx);
    }
    print(ans);
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
