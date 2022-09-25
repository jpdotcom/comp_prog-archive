#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll a, ll b, ll p){
    ll ans=1;
    a%=p;  
    while(b){
        if(b&1)
            ans=(ans*a)%p;
        b/=2;
        a=(a*a)%p;
    }
    return ans;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const int maxN=1e7+1;
int ans[maxN];
int primes[maxN];
void sieve(){
    FOR(maxN) primes[i]=i;
    for (int i=2;i<=sqrt(maxN);i++){
        if (primes[i]==i){
            for (int j=i*i;j<maxN;j+=i){
                primes[j]=i;
            }
        }
    }
}
void get(int x ){
    unordered_set<int> seen;
    while (x!=1){
        if (seen.find(primes[x])==seen.end()){
            ans[primes[x]]++;
            seen.insert(primes[x]);
        }
        x/=primes[x];
    }
}
void solve() {
    int n;
    cin>>n;
    FOR(n){
        int val; cin>>val;
        get(val);
    }
    int m; cin>>m;
    for (int j=1;j<maxN;j++) ans[j]+=ans[j-1];
    FOR(m){
        int l,r;
        cin>>l>>r;
        r=min((int)1e7,r);
        l=min((int)1e7,l);
        print(ans[r]-ans[l-1]);
    }
}


void precompute(){
    sieve();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    int i=0;
    while (t--){
        solve();
    }
     
}
