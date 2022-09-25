#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1LL)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6;
void solve(){
    ll n,k; cin>>n>>k;
    if (log2l(k)>n-1){
        print(-1);
        return;
    }
    k--;
    stack<vi> vals;
    vi curr;
    bitset<maxN> b(k);
    for (int i=n;i;i--){
        curr.pb(i);
        if (b[n-i]==0){
            vals.push(curr);
            curr.clear();
        }
    }
    if (curr.size()>0) vals.push(curr);
    while (vals.size()){
        vi p=vals.top();
        vals.pop();
        for (int c: p) cout<<c<<' ';
    }
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t; cin>>t;
    while (t--){
        solve();
    }
}
