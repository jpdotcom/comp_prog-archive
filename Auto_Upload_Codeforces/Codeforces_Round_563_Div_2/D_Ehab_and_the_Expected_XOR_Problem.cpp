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
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1e6+1;
bool used[maxN];
void solve(){
    int n,x; cin>>n>>x;
    n=(1<<n);
    fill(used,used+n+1,false);
    vector<int>out;
    for (int i=1;i<=n-1;i++){
        if (!used[i] && i!=x){
            out.pb(i);
            if ((i^x)<=n-1) used[i^x]=true;
            used[i]=true;
        }
    }
    print(out.size());
    if (out.size()!=0){
        cout<<out[0]<<' ';
        for (int i=1;i<out.size();i++){
            cout<<(out[i]^out[i-1])<<' ';
        }
        cout<<endl;
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
