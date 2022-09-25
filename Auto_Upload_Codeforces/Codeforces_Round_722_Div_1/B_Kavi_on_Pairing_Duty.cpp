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
#define put push
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=1e6+5;
ll dp[maxN];
int primes[maxN];
ll get(int n){
    vi vals;
    while (n>1){
        vals.pb(primes[n]);
        n/=primes[n];
    }
    sort(vals.begin(),vals.end());
    ll s=1;
    ll c=1;
    for (int i=1;i<(int)vals.size();i++){
        if (vals[i]==vals[i-1]) c++;
        else{
            s*=(c+1);
            c=1;
        }
    }
    s*=(c+1);
    return s;
}
const int MOD=998244353;
void solve(){
    int n; cin>>n;
    dp[0]=1;
    dp[1]=1;
    ll s=2;
    for (int i=2;i<=n;i++){
        dp[i]=s+(get(i)-1);
        dp[i]%=MOD;
        s+=dp[i];
        s%=MOD;
    }
    print(dp[n]);
}
void precompute(){
    primes[2]=2;
    FOR(maxN) primes[i]=i;
    for (int i=2;i<sqrt(maxN)+1;i++){
        if (primes[i]==i){
            for (int j=i*i;j<maxN;j+=i) primes[j]=i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}


