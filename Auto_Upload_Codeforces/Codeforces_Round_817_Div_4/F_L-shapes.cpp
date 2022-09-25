#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=55;
int a[maxN][maxN];
int used[maxN][maxN];
bool close(pi u, pi v){

    return (abs(u.F-v.F)+abs(u.S-v.S))<=2 && abs(u.F-v.F)!=2 && abs(u.S-v.S)!=2;
}
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> L;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char v; cin>>v;
            if (v=='.'){
                used[i][j]=true;
            }
            else{
                used[i][j]=0;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (used[i][j]) continue;
            if (i+1<n && j+1<m && !used[i+1][j] && !used[i][j+1]){
                used[i][j]=used[i+1][j]=used[i][j+1]=1;
                L.push_back(vector<pair<int,int>>{mp(i,j),mp(i+1,j),mp(i,j+1)});
                continue;
            }
            if (i-1>-1 && j+1<m && !used[i-1][j] && !used[i][j+1]){
                used[i][j]=used[i-1][j]=used[i][j+1]=1;
                L.push_back(vector<pair<int,int>>{mp(i,j),mp(i-1,j),mp(i,j+1)});
                continue;
            }
            if (i+1<n && j-1>-1 && !used[i+1][j] && !used[i][j-1]){
                used[i][j]=used[i+1][j]=used[i][j-1]=1;
                L.push_back(vector<pair<int,int>>{mp(i,j),mp(i+1,j),mp(i,j-1)});
            }
            if (i-1>-1 && j-1>-1 && !used[i-1][j] && !used[i][j-1]){
                used[i][j]=used[i-1][j]=used[i][j-1]=1;
                L.push_back(vector<pair<int,int>>{mp(i,j),mp(i-1,j),mp(i,j-1)});
            }

            
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!used[i][j]){
                print("NO");
                return;
            }
        }
    }
    bool ok=true;
    for (int i=0;i<L.size();i++){
        for (int j=i+1;j<L.size();j++){
            for (pi u: L[i]){
                for (pi v: L[j]){
                    ok&=!(close(u,v));
                }
            }
        }
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
    int i=1;
    while (t--){
        solve();
        ++i;
    }
}
