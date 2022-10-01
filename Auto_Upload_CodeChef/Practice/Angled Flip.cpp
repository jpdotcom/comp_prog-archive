#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
#define insert(x) push(x)
using namespace std;
using namespace __gnu_pbds;
map<int,pair<int,int>> cnt;
map<int,pair<int,int>> cnt2;
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>> c(n,vector<int>(m));
    cnt.clear(),cnt2.clear();
    if (n==1 || m==1){
        vector<vector<int>> A(n,vector<int>(m));
        vector<vector<int>> B(n,vector<int>(m));
        bool ok=true;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>A[i][j];
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>B[i][j];
                ok&=A[i][j]==B[i][j];
            }
        }
        if (ok) print("YES");
        else print("NO");
        return;

    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (i==0 && j==0) c[i][j]=0;
            else if (j==0) c[i][j]=c[i-1][j]^1;
            else c[i][j]=c[i][j-1]^1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int v; cin>>v;
            if (cnt.find(v)==cnt.end()) cnt[v].F=cnt[v].S=0;
            if (c[i][j]) cnt[v].S++;
            else cnt[v].F++;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int v; cin>>v;
            if (cnt2.find(v)==cnt2.end()) cnt2[v].F=cnt2[v].S=0;
            if (c[i][j]) cnt2[v].S++;
            else cnt2[v].F++;
        }
    }
    bool ok=true;
    for (auto &it : cnt){
        if (it.S!=cnt2[it.F]) ok=false;
    }
    if (ok) print("YES");
    else print("NO");

    
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
    while (t--){
        solve();
        
    }
}