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
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6;
ll get_sum(ll i, ll j){
    return j*(j+1)/2-i*(i-1)/2;
}
void solve(){
    int n; cin>>n;
    ll mx=n*(1e9+1);
    if (n==1){
        print(1);
        return;
    }
    else if (n==2){
        cout<<3<<' '<<1<<endl;
        return;
    }
    vector<ll> found;
    for (ll i=1;i<=sqrt(mx);i++){
        ll l=1,r=1e9;
        if (i+1<n) continue;
        while (l<=r){

            ll mid=l+(r-l)/2;
            ll s1=get_sum(mid+1,mid+n-2);
            ll s2=get_sum(mid+i-n+2,mid+i-1);
            ll check=i*i-2*mid-i;
            if (s1>check) r=mid-1;
            else if (s2<check) l=mid+1;
            else{
                found={mid,mid+i,i*i};
                break;
            }
        }
        if (found.size()>0) break;
    }
    assert(found.size()>0);
    vector<ll> out;
    ll s=0;
    for (ll i=found[0];i<found[1] && out.size()<n;i++){
        s+=i;
        out.pb(i);
    }
    int idx=n-1;
    mx=found[1];
    while (s<found[2] && idx>-1){
        ll add=min(found[2]-s+out[idx],mx);
        s-=out[idx];
        s+=add;
        if (add==mx) mx--;
        out[idx]=add;
        idx--;
    }
    for (ll x: out) cout<<x<<' ';
    cout<<endl;

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
