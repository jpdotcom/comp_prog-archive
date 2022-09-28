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
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
pair<int,int> a[maxN];
int prefix[maxN][31][2];
void solve(){
    int n,c; cin>>n>>c;
    FOR(n) cin>>a[i].F>>a[i].S;
    for (int i=0;i<n+1;i++){
        for (int j=0;j<31;j++){
            for (int k=0;k<2;k++){
                if (i==0) prefix[i][j][k]=k;
                else{
                    if (a[i-1].F==1) prefix[i][j][k]=prefix[i-1][j][k]&bit(a[i-1].S,j);
                    else if (a[i-1].F==2) prefix[i][j][k]=prefix[i-1][j][k]|bit(a[i-1].S,j);
                    else prefix[i][j][k]=prefix[i-1][j][k]^bit(a[i-1].S,j);
                }
            }
        }
    }
    int x=c;
    for (int i=0;i<n;i++){
        int nx=0;
        for (int j=0;j<31;j++){
            nx+=prefix[i+1][j][bit(x,j)]<<j;
        }
        print(nx);
        x=nx;
    }
}
void precompute(){
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    while (t--) solve();
}
