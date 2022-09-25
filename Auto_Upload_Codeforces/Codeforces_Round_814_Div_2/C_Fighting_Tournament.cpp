#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
#define int ll
const int maxN=2e5+200;
int a[maxN];
void solve(){
    int n; cin>>n;
    int q; cin>>q;
    int mx=0,idx=0;
     FOR(n){
        cin>>a[i];
        if (mx<a[i]){
            mx=a[i];
            idx=i;
        }
    }
    vector<vector<int>> vals(n,vector<int>());
    int mx_round=0;
    if (idx!=0){
        int round=0;
        int curr_idx=0;
        for (int i=1;i!=idx && i<n;i++){
            if (a[curr_idx]>a[i]){
                vals[curr_idx].pb(++round);
            }
            else{
                curr_idx=i;
                vals[curr_idx].pb(++round);
            }
        }
        mx_round=round;
    }
    FOR(q){
        int j,k; cin>>j>>k;j--;
        if (j!=idx){
            if (vals[j].size()>0){
                int v=upper_bound(vals[j].begin(),vals[j].end(),k)-vals[j].begin();
                cout<<v<<endl;
            }
            else print(0);
        }
        else cout<<max(0ll,k-mx_round)<<endl;
    }
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
    cin>>t;
    while (t--)
    {
        solve();
    }
}
