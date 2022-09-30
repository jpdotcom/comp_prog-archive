
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
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
int va(int a, int b, int c, int x,int y, int z){
    return (a>0 && b>0 && c>0 && (a^b)==x && (b^c) == y && (a^c) == z  && !(a==b || b==c || a==b));
}
int g(int a,int b){
    return b%2>a%2;
}
void solve(){
    int x,y; cin>>x>>y;
    int z=x^y;
    int v[3]={x,y,z};
    sort(v,v+3,g);
            int ans[3]={v[2]^2,v[1]^2,2};
            sort(ans,ans+3);
            cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
            return;
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
