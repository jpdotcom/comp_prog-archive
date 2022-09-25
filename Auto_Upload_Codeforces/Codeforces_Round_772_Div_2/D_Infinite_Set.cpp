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
const int maxN=2e5+5;
ll a[maxN];
unordered_set<int>cnt;
long long dp[maxN];
bool useless(int v){
    if (cnt.find(v)!=cnt.end()) return true;
    else if (v==0) return false;
    if (v&1) return useless((v-1)/2);
    else if (v%4 == 0) return useless(v/4);
    else return false;
}
void solve(){
    cnt.clear();
    int n,p; cin>>n>>p;
    FOR(n) cin>>a[i];
    sort(a,a+n);
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<p+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=MOD;
    }
    for (int i=1;i<=p;i++){
        dp[i]+=dp[i-1];
        dp[i]%=MOD;
    }
    ll ans=0;
    for (int i=0;i<n;i++){
        if (!useless(a[i])){
            int b=log2(a[i])+1;
            if (p-b>=0){
            ans+=dp[p-b];
            ans%=MOD;
            }
        }
        cnt.insert(a[i]);
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
    while (t--){
        solve();
    }
}
