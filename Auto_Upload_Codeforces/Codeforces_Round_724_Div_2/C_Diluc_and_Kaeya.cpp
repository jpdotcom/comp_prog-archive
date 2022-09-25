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
const int maxN=5e5+1;
map<pi,int> cnt;
int dp[maxN];
void solve(){
    cnt.clear();
    int n; cin>>n;
    string s; cin>>s;
    int d=0;
    FOR(n){
        dp[i]=1;
        d+=(s[i]=='D');
        pi c=make_pair((i+1-d)/gcd(i+1-d,d),d/gcd(d,i+1-d));
        if (cnt.find(c)!=cnt.end()){
            dp[i]=cnt[c]+1;
        }
        if (cnt.find(c)==cnt.end()) cnt[c]=0;
        cnt[c]=max(cnt[c],dp[i]);
    }
    FOR(n){
        cout<<dp[i]<<' ';
    }
    cout<<endl;
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
