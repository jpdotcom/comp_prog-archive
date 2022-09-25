#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
pi a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i].S>>a[i].F;
    sort(a,a+n);
    int i=0,j=n-1;
    ll t=0;
    ll c=0;
    while (i<=j){
        if (t>=a[i].F){
            c+=a[i].S;
            t+=a[i].S;
            i++;
        }
        else{
            ll v=min(a[i].F-t,a[j].S);
            c+=2*v;
            t+=v;
            a[j].S-=v;
            if (a[j].S==0) j--;
        }
    }
    print(c);

}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
