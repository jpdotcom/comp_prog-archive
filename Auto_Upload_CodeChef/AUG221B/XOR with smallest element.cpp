#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
#define insert(x) push(x)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
int a[maxN];
int mark[maxN];
void solve(){
    priority_queue<pair<int,int>> pq;
    int n,x,y; cin>>n>>x>>y;
    FOR(n){
        int v; cin>>v;
        pq.push(mp(-1*v,i));
    }
    while (y){
        pi v= pq.top();
        pq.pop();
        v.F*=-1;
        y--;
        if ((v.F^x)<=v.F){
            v.F^=x;
            y=y&1;
            if (y){
                v.F^=x;
                y--;
            }
        }
        else v.F^=x;
        v.F*=-1;
        pq.push(v);
    }
    while (pq.size()){
        cout<<-1*pq.top().F<<' ';
        pq.pop();
    }
    cout<<endl;
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
    cin>>t;
    while (t--){
        solve();
        
    }
}
