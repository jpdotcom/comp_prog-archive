#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n+1) cin>>a[i];
    int v[3]={0,0,0};
    int end=pow(2,(int)log2(n));
    vi need;
    for (int i=end,j=(int)log2(n);i>=1;i/=2,j--){
        int s=(a[i]-a[0])/i;
        need.pb((3-s)/2);
    }
    reverse(need.begin(),need.end());
    for (int i=need.size()-1;i>=0;i--){
        pi c[3]={make_pair(n-v[0],0),make_pair(n-v[1],1),make_pair(n-v[2],2)};
        sort(c,c+3);
        for (int j=0;j<need[i];j++){
            v[c[2-j].S]+=(1<<i);
        }
    }
    cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;
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
    while (t--){
        solve();
    }
}


