#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=4e5+1;
vector<vector<int>> facs(maxN);
int lg2[maxN];
int p[maxN][4];
void solve()
{

    int l,r;
    cin>>l>>r;
    ll invalid=0;
    for (int i=l;i<=r;i++){
        int f=facs[i].size()-(lower_bound(facs[i].begin(),facs[i].end(),l)-facs[i].begin());
        invalid+=(ll)(f-1)*(f-2)/2;
        ll q=i/(1<<lg2[i]);
        vector<ll> v1;
        vector<ll> v2;
        for (auto x: facs[2*i]){
            if (i%x==0) continue;
            if (x>=l && x<=r && x<i && lg2[x]==lg2[i]+1){
                v1.pb(x);
            }
        }
        for (auto x: facs[i]){
                if (x>=l && x<=r && x<i) v2.pb(x);
        }
        sort(v2.begin(),v2.end());
        sort(v1.begin(),v1.end());
        for (int j=0;j<(int)v1.size();j++){
           int add=v2.size()-(upper_bound(v2.begin(),v2.end(),max((ll)l-1,i-v1[j]))-v2.begin()+1);
           invalid+=add+1;
           add=v1.size()-(upper_bound(v1.begin(),v1.end(),max(i-v1[j],v1[j]))-v1.begin()+1);
           invalid+=add+1;
        }
    }
    ll tot=(ll)(r-l+1)*(r-l)*(r-l-1)/6;
    print(tot-invalid);
}
void precompute(){
    for (int i=1;i<maxN;i++){
        if (i%2) lg2[i]=0;
        else lg2[i]=lg2[i/2]+1;
        for (int j=1;j<=(int)sqrt(i);j++){
            ll a=j,b=i/j;
            if (a*b==i){
                facs[i].pb(a);
                if (a!=b) facs[i].pb(b);
            }
        }
        sort(facs[i].begin(),facs[i].end());
    }
    p[1][0]=1;
    p[1][1]=1;
    p[1][2]=1;
    p[1][3]=1;
    for (int i=2;i<maxN;i++){
        for (int j=0;j<4;j++){
            if (!j) p[i][j]=1;
            else p[i][j]+=p[i][j-1]+p[i-1][j];
        }
    }
}
int32_t main(){
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
