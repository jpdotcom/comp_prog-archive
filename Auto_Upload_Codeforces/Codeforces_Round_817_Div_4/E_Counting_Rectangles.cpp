#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a,b) for (int a=0;a<=b;a++)
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
ll table[1005][1005];

ll sum(int a,int b, int c, int d){
    return table[c][d]-table[c][b-1]-table[a-1][d]+table[a-1][b-1];
}
void solve(){
    int n,q; cin>>n>>q;
    memset(table,0,sizeof(table));
    for (int i=0;i<n;i++){
        int h,w; cin>>h>>w;
        table[h][w]+=h*w;
    }
    for (int i=1;i<1005;i++){
        for (int j=1;j<1005;j++){
            table[i][j]+=table[i-1][j]+table[i][j-1]-table[i-1][j-1];
        }
    }
    for (int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a>=c-1 || b>=d-1) print(0);
        else print(sum(a+1,b+1,c-1,d-1));
    }
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
