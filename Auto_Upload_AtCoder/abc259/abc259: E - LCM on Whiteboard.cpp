#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
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
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
map<int,pi> cnt;
void solve(){
    int n; cin>>n;
    vector<vector<pi>> vals;
    for (int i=0;i<n;i++){
        int m; cin>>m;
        vector<pi> v;
        for (int j=0;j<m;j++){
            int p,c; cin>>p>>c; 
            v.pb(mp(p,c));
        }
        vals.pb(v);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<vals[i].size();j++){
            int p=vals[i][j].F,c=vals[i][j].S;
            if (cnt[p].F==c)
                cnt[p].S++;
            else if (cnt[p].F<c)
                cnt[p]=mp(c,1);
        }
    }
    int ans=0;
    int add=0;
    for (int i=0;i<n;i++){
        bool ok=false;
        for (int j=0;j<vals[i].size();j++){
            if (cnt[vals[i][j].F].F==vals[i][j].S && cnt[vals[i][j].F].S==1) ok=1;
        }
        ans+=ok;
        add|=(!ok);
    }
    print(ans+add);
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
    while (t--){
        solve();
    }
}


