#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6;
int longest[maxN];
int tail[maxN];
void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    memset(longest,0,4*n);
    memset(tail,0,4*n);
    FOR((int)s.size()){
        int v=(s[i]=='1');
        if (v && i) v+=longest[i-1];
        longest[i]=v;
    }
    for (int i=n-1;~i;i--){
        int v=(s[i]=='1');
        if (v && i!=n-1) v+=tail[i+1];
        tail[i]=v;
    }
    int ans=tail[k]+k;
    for (int i=0;i<n-k;i++){
        ans=max(longest[i]+k+tail[i+k+1],ans);
    }
    print(ans);
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    int i=1;
    cin>>t;
    while (t--)
    {
        solve();
        ++i;
    }
}
