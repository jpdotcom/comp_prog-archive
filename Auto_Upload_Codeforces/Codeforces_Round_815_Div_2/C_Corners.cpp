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
const int maxN=1000;
int a[maxN][maxN];

int n,m; 
int valid(int i, int j){

    return 0<=i && i<n && 0<=j && j<m;
}
void solve(){
    int total=0;
    cin>>n>>m;
    FOR(n){
        string s; cin>>s;
        for (int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
            total+=a[i][j];
        }
    }
    int loss=min(total,3);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (valid(i+1,j) && valid(i,j+1)){
                int v=a[i][j];
                v+=a[i+1][j]+a[i][j+1];
                if (v>0) loss=min(loss,v);
            }
            if (valid(i+1,j) && valid(i,j-1)){
                int v=a[i][j];
                v+=a[i+1][j]+a[i][j-1];
                if (v>0) loss=min(loss,v);
            }
            if (valid(i-1,j) && valid(i,j+1)){
                int v=a[i][j];
                v+=a[i-1][j]+a[i][j+1];
                if (v>0) loss=min(loss,v);
            }
            if (valid(i-1,j) && valid(i,j-1)){
                int v=a[i][j];
                v+=a[i-1][j]+a[i][j-1];
                if (v>0) loss=min(loss,v);
            }
        }
    }
    if (total==0) print(0);
    else print(total-loss+1);
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
