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
#define INF ((ll)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=3e5+1;
int a[maxN];
int n;
bool seen[maxN];
void solve(){
    cin>>n;
    FOR(n) cin>>a[i];
    FOR(n+1) seen[i]=0;
    int l=0,r=n-1;
    while (l<=r && (a[l]==0 || a[r]==0)){
        if (a[l]==0) l++;
        if (a[r]==0) r--;
    }
    if (l>r){
        print(0);
        return;
    }
    int idx=0;
    for (int i=l;i<=r;i++){
        if (a[i]<=n) seen[a[i]]=true;
        while (seen[idx]) idx++;
    }
    print((idx==0 ? 1 : 2));

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
