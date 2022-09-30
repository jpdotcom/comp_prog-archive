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
const int maxN=1e5+1;
ll a[maxN];
void solve(){
    int n; cin>>n;
    ll s=0;
    FOR(n){
        cin>>a[i];
        s+=a[i];
    }
    sort(a,a+n);
    bool ok=true;
    FOR(n-1) if (a[i]!=a[i+1]) ok=false;
    if (ok){
        print(0);
        return;
    }
    ll curr=0;
    for (int i=n-1,cnt=1;~i;i--,cnt++){
        s-=a[i];
        curr+=a[i];
        if ((n-cnt)*(i!=0 ? a[i-1]: 0) -s<=curr){
            print(cnt);
            return;
        }
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
    while (t--)
    {solve();
    }
}
