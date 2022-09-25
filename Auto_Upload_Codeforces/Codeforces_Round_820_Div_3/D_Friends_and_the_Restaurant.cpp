#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for (int i=0;i<a;i++)
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
#define INF (1e9)
#define endl '\n'
#define MOD ((int)998244353)
using namespace std;
const int maxN=1e6;
int a[maxN];
int b[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    vi vals(n);
    FOR(n){
        cin>>b[i];
        int d=b[i]-a[i];
        vals[i]=d;
    }
    int j=n-1;
    sort(vals.begin(),vals.end());
    reverse(vals.begin(),vals.end());
    int ans=0;
    for (int i=0;i<n && i<j;i++,j--){
        while (j>i && vals[i]+vals[j]<0) j--;
        ans+=(j>i);
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
