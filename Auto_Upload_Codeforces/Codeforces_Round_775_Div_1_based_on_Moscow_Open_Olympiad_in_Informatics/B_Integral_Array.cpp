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
const int maxN=4e6+1;
int a[maxN];
ll cnt[maxN];
ll prefix[maxN];
int has[maxN];
void solve(){
    int n,c; cin>>n>>c;
    fill(cnt,cnt+2*c+1,0);
    fill(prefix,prefix+2*c,0);
    fill(has,has+2*c+1,0);
    FOR(n){
        cin>>a[i];
        prefix[a[i]]++;
        has[a[i]]|=1;
    }
    for (int i=1;i<=2*c;i++){
        prefix[i]+=prefix[i-1];
    }
    for (int i=1;i<=c;i++){
        if (has[i]){
        for (int j=i,s=1;j<=c;j+=i,s++){
            cnt[s]+=prefix[j+i-1]-(j-1>=0 ? prefix[j-1] : 0);
        }
        }
    }
    int ans=0;
    bool ok=true;
    int u=0;
    FOR(2*c+1) u+=has[i];
    for (int i=1;i<=c;i++){
        if (has[i]) ans+=cnt[i]>0;
        if (cnt[i]>0 && !has[i]) ok=false;
    }
    print(((ans==u && ok) ? "YES" : "NO"));
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
