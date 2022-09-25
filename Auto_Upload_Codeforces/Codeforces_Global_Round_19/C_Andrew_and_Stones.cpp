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
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
int a[maxN];
void solve(){
    int n;cin>>n;
    ll s=0;
    FOR(n){
        cin>>a[i];
        if (1<=i && i<n-1) s+=a[i];
    }
    int cnt1=0;
    int o=0;
    for (int i=1;i<n-1;i++){
        cnt1+=a[i]==1;
        o+=(a[i]&1);
    }
    if (cnt1==n-2 || n-2==1 && a[1]&1){
        print(-1);
    }
    else{
        if (o==n-2) print(s/2+(o-1)/2+1);
        else print(s/2+(o+1)/2);
    }
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
