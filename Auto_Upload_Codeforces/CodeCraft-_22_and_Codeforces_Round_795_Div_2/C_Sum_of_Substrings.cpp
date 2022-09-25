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
void solve(){
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int ans=0;
    if (n==1){
        print(0);
    }
    FOR(n){
        if (i==0) ans+=10*(s[i]-48);
        else if (i==n-1) ans+=1*(s[i]-48);
        else ans+=11*(s[i]-48);
    }
    int move_idx=-1;
    for (int i=n-1;i>=max(0,n-k-1);i--){
        if (s[i]=='1' && i!=n-1){
            ans-=((i==0) ? 9 : 10);
            k-=(n-1-i);
            move_idx=i;
            break;
        }
        else if (s[i]=='1'){
            move_idx=n-1;
            break;
        }
    }
    for (int i=0;i<min(k+1,n);i++){
        if (s[i]=='1' && i!=0 && i!=move_idx){
            ans-=1;
            k-=i;
            break;
        }
        else if (s[i]=='1'){
            break;
        }
    }
    print(ans);
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
