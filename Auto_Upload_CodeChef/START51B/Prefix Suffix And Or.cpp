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
#define MOD ((ll)998244353);
using namespace std;
const int maxN=1e5+1;;
int a[maxN];
void solve(){
    int n,k; cin>>n>>k;
    FOR(n) cin>>a[i];
    map<int,int> l;
    map<int,int> r;
    ll ans=1;
    for (int i=0;i<k;i++){
        vector<int> b(n);
        l.clear(),r.clear();
        ll temp=0;
        for (int j=0;j<n;j++){
            b[j]=a[j]&1;
            a[j]>>=1;
        }
        for (int j=0;j<n;j++) r[b[j]]++;
        for (int j=0;j<n;j++){
            r[b[j]]--;
            l[b[j]]++;
            if (b[j]==1) temp+=r[0];
            temp%=MOD;
        }
        temp+=n+1;
        temp%=MOD;
        ans*=temp;
        ans%=MOD;
    }
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
    while (t--) solve();
}
