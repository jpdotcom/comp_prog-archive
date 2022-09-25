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
#define INF (1e18)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1e6+1;
ll blockS[maxN];
ll perBlock[maxN];
ll suffix[maxN];
ll prefix[maxN];
ll ccSum[maxN];
int ls[maxN];
int lp[maxN];
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>> arrs;
    vector<int> indices(m);
    ll ans=-1*INF;
    FOR(n){
        int v; cin>>v;
        vector<ll>vals(v);
        prefix[i]=suffix[i]=perBlock[i]=blockS[i]=ls[i]=lp[i]=0;
        ll s=0;
        for (int j=0;j<v;j++)
        {
            cin>>vals[j];
            s+=vals[j];
            if (s>=prefix[i]){
                prefix[i]=s;
                lp[i]=j+1;
            }
        }
        blockS[i]=s;
        s=0;
        for (int j=v-1;~j;j--){
            s+=vals[j];
            if (s>=suffix[i]){
                suffix[i]=s;
                ls[i]=n-j;
            }
        }
        ll tans=vals[0];
        perBlock[i]=vals[0];
        for (int j=1;j<v;j++){
            tans=max(tans+vals[j],vals[j]);
            perBlock[i]=max(perBlock[i],tans);
        }
    }
    FOR(m){
        cin>>indices[i];
        indices[i]--;
        ans=max(ans,perBlock[indices[i]]);
    }
    ccSum[0]=blockS[indices[0]];
    for (int i=1;i<m;i++) ccSum[i]=ccSum[i-1]+blockS[indices[i]];
    ll cm=ccSum[m-1];
    for (int i=m-2;~i;i--){
        int idx=indices[i];
        ans=max(ans,suffix[idx]-ccSum[i]+cm);
        cm=max(cm,ccSum[i]+prefix[indices[i+1]]);
        if (ls[idx]+lp[indices[i+1]]) ans=max(suffix[idx]+prefix[indices[i+1]],ans);
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
    while (t--) solve();
}
