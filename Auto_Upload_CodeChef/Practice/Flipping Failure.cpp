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
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=2e5+1;
int prefix[maxN];
void solve(){
    string s;cin>>s;
    int n=s.size();
    prefix[0]=0;
    for (int i=1;i<=s.size();i++){
        prefix[i]=prefix[i-1]+(s[i-1]=='1');
    }
    int v=0;
    vector<int> vals;
    for (int i=n-prefix[n];i<n;i++) v+=(s[i]=='1');
    int ans=prefix[n]-v;
    int one_idx=0;
    for (int i=0;i<n;i++){
        if (s[i]=='1') vals.pb(n-prefix[n]+i);
        while (one_idx<vals.size() && vals[one_idx]<=i) one_idx++;
        if (i>=n-prefix[n]){
            ans=min(ans,prefix[i+1]-one_idx);
        }
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
    cin>>t;
    while (t--) solve();
}
