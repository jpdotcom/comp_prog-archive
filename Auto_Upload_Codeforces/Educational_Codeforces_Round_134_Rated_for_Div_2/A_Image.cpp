#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)998244353);
using namespace std;
const int maxN=1e5+1;;
void solve(){
    vector<int> cnt(26,0);
    string s1,s2; cin>>s1>>s2;
    FOR(2){
        cnt[s1[i]-'a']++;
        cnt[s2[i]-'a']++;
    }
    int ds=0;
    int ans=3;
    FOR(26){
        if (cnt[i]<=1) ans=min(ans,3);
        if (cnt[i]==4) ans=0;
        if (cnt[i]==3) ans=min(ans,1);
        if (cnt[i]==2) ans=min(ans,2);
        ds+=(cnt[i]==2);
    }
    if (ds>=2) ans=min(ans,1);
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}
