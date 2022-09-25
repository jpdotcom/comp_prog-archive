#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6;
string s;
ll prefix[maxN];
map<ll,set<int>> vals;
bool rev(int a, int b){
    return a>b;
}
ll get(int l, int r){
    if (l>=r) return 0;
    ll ans=1;
    int i=l;
    while (i<=r){
        int s=(i-1 == -1 ? 0 : prefix[i-1]);
        int v=*vals[s].begin();
        vals[s].erase(v);
        vals[prefix[i]].erase(i);
        ans+=get(i+1,v-1);
        i=v+1;
    }
    return ans;
}
void solve(){
    int n; cin>>n;
    vals.clear();
    n*=2;
    cin>>s;
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=(s[i]=='(' ? 1: -1);
        vals[sum].insert(i);
        prefix[i]=sum;
    }
    print(get(0,n-1));
}
void precompute(){

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}

