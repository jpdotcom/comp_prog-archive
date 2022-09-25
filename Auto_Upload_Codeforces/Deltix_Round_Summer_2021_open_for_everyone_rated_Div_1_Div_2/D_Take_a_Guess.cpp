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
//#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)

using namespace std::chrono;
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=4e5+1;
int vals[maxN];
void solve()
{
    int n,k; cin>>n>>k;
    for (int i=0;i<n-1;i++){
        cout<<"or " << i+1 << " " <<(i+1)%n+1<<endl;
        int v1; cin>>v1;
        cout<<"and " <<i+1 <<" "<<(i+1)%n+1<<endl;
        int v2; cin>>v2;
        int x=v1^v2;
        vals[i]=2*v2+x;
    }
        cout<<"or " << 1 << " " <<3<<endl;
        int v1; cin>>v1;
        cout<<"and " <<1 <<" "<<3<<endl;
        int v2; cin>>v2;
        int x=v1^v2;
    int third=2*v2+x;
    int alt=1;
    int out[n];
    int curr=(vals[0]-vals[1]+third)>>1;
    out[0]=curr;
    for (int i=0;i<n-1;++i){
        curr=vals[i]-curr;
        out[i+1]=curr;
    }
    sort(out,out+n);
    cout<<"finish "<<out[--k]<<endl;

}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
