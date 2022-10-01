#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
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
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
inline void hash_combine(std::size_t& seed) { }

template <typename T, typename... Rest>
inline void hash_combine(std::size_t& seed, const T& v, Rest... rest) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    hash_combine(seed, rest...);
}
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {   
        size_t h=0;
        hash_combine(h,p.F,p.S);
        return h;
    }
};
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
ll gcd(ll a, ll b){
    if (a>b) swap(a,b);
    if (!a) return b;
    return gcd(b%a,a);
}
const int mxN=1e5+1;
ll p[mxN];
unordered_map<pair<int, int>, int, hash_pair> cnt;
void solve(){
    int n,k; cin>>n>>k;
    cnt.clear();
    p[0]=0;
    FOR(n){
        int val; cin>>val;
        p[i+1]=(val^p[i]);
    }
    FOR(32){
        cnt[make_pair(0,i)]=0;
    }
    int ans=1e9+1;
    FOR(n){
        int v=p[i+1];
        int c=0;
        int curr=-1;
        for (int j=30;j>=0;j--){
            if (bit(v,j)==1 && bit(k,j)==0){
                pi s=make_pair(c,j);
                if (cnt.find(s)!=cnt.end()) curr=max(curr,cnt[s]);
                c+=1;
            }
            else if (bit(v,j)==0 && bit(k,j)==0){
                pi s=make_pair(c+1,j);
                if (cnt.find(s)!=cnt.end()) curr=max(curr,cnt[s]);
            }
            else if (bit(v,j)==0 && bit(k,j)==1) c+=1;
            c*=2;
        }
        c/=2;
        pi s=make_pair(c,0);
        if (cnt.find(s)!=cnt.end()) curr=max(curr,cnt[s]);
        if (curr!=-1) ans=min(ans,i+1-curr);
        for (int j=0;j<=31;j++){ 
            pi s=make_pair(p[i+1],j);
            cnt[s]=i+1;
            p[i+1]>>=1;
        }
    }
    print(((ans==1e9+1) ? -1 : ans));
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
