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
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+1;
bool comp(vector<int> a, vector<int> b){
    return ((b[0]>a[0]));
}
bool comp2(vector<int>& a , vector<int>& b){
    return ((b[1]>a[1]));
}
void solve(){
    int n; cin>>n;
    vector<vector<int>> q;
    priority_queue<pair<int,int>> h;
    FOR(n){
        int v; cin>>v;
        vi x;
        if (v==0){
            x.pb(n),x.pb(i+2);x.pb(i+1);
        }
        else{
        int l=max((i+1)/(v+1)+1,1);
        int u=min((i+1)/v ,n);
        x.pb(u), x.pb(l), x.pb(i+1);
        }
        q.pb(x);
    }

    sort(q.begin(),q.end(),comp2);
    vi out(n+1);
    int idx=0;
    for (int i=1;i<=n;i++){
        while (idx<n && q[idx][1]==i){
            h.push(mp(-1*q[idx][0],q[idx][2]));
            idx++;
        }
        pi p=h.top();
        h.pop();
        out[p.S]=i;
    }
    for (int i=1;i<=n;i++) cout<<out[i]<<' ';
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
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
