#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) (a.begin(),a.end())
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e5+10;
void solve(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    map<pair<char,char>,int> cnt;
    int eq_count=0;
    FOR((int)s.size()){

        char c1=min(s[i],t[n-1-i]);
        char c2=max(s[i],t[n-1-i]);
        cnt[mp(c1,c2)]++;
    }
    int bad=0;
    for (auto &it : cnt){
        bad+=(it.S%2);
        eq_count+=(it.S%2 && it.F.S==it.F.F);
    }
    if (n&1){
        if (bad==0 || (bad==1 && eq_count==1)) print("YES");
        else print("NO");
    }
    else if (bad) print("NO");
    else print("YES");
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}

