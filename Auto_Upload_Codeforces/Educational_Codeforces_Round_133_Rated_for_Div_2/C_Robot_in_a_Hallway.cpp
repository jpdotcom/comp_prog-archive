#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+1)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
int a[2][maxN];
int cw[maxN];
int ccw[maxN];
void solve(){
    int n; cin>>n;
    FOR(2){
        for (int j=0;j<n;j++){
             cin>>a[i][j];
            if (i + j > 0) a[i][j]++;
        }
    }
    ccw[n]=cw[n]=0;
    for (int i=n-1;i>=0;i--){
        ccw[i]=max(ccw[i+1]+1,max(a[0][i],a[1][i]+(2*(n-i)-1)));
        cw[i]=max(cw[i+1]+1,max(a[1][i],a[0][i]+2*(n-i)-1));
    }
    int ans=1e9+1e8;
    int curr_t=-1;
    for (int i=0;i<n;i++){
        //zig-zag till before i
        ans=min(ans,max(curr_t+2*(n-i-1)+2,((i&1)==0 ? cw[i] : ccw[i])));
        if (i&1){
            curr_t=max(curr_t+1,a[1][i]);
            curr_t=max(curr_t+1,a[0][i]);
        }
        else{
            curr_t=max(curr_t+1,a[0][i]);
            curr_t=max(curr_t+1,a[1][i]);
        }
    }
    ans=min(ans,curr_t);
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
    while (t--){
        solve();
    }
}
