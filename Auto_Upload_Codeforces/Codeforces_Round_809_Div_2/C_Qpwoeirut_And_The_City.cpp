#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+10;
ll a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    ll ans=1e9+7;
    ll temp=0;
    for (int i=1;i<n-1;i+=2){
          temp+=max(0LL,max(a[i-1],a[i+1])-a[i]+1);
    }
    ans=temp;
    if ((n&1)==0){
        vector<ll> min_vals(n+1);
        min_vals[n-1]=0;
        for (int i=n-2;i>=0;i--){
            min_vals[i]=max(0LL,max(a[i+1],a[i-1])-a[i]+1);
            if (i+2<n) min_vals[i]+=min_vals[i+2];
        }
        temp=0;
        for (int i=1;i<n-1;i+=2){
            ans=min(ans,temp+min_vals[i]);
            ans=min(ans,temp+min_vals[i+1]);
            temp+=max(0LL,max(a[i+1],a[i-1])-a[i]+1);
        }
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
    while (t--){
        solve();
    }
}
