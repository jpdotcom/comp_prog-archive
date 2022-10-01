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
ll mi[maxN];
void solve(){
    int n,m; cin>>m>>n;
    vector<vector<ll>> A(n,vector<ll>(m));
    fill(mi,mi+m+1,0);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>A[j][i];
            mi[i]+=A[j][i];
        }
    }
    ll ans=0;
    for (int i=0;i<n;i++){
        ll temp=0;
        for (int j=0;j<m;j++){
            temp+=max(0LL,n*A[i][j]-mi[j]);
        }
        ans=max(ans,temp);
    }
    for (int i=0;i<n;i++){
        ll temp=0;
        for (int j=0;j<m;j++){
            temp+=max(0LL,mi[j]-n*A[i][j]);
        }
        ans=max(ans,temp);
    }
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
