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
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
vi squares;
void solve(){
    int n; cin>>n;
    vector<int> occ(n,-1);
    for (int i=n-1;~i;i--){
        bool ok=false;
        for (int j=squares.size()-1;~j;j--){
            int idx=squares[j]-i;
            if (0<=idx && idx<n && occ[idx]==-1){
                occ[idx]=i;
                ok=true;
                break;
            }
        }
        if (!ok){
            print(-1);
            return;
        }
    }
    for (auto x: occ) cout<<x<<' ';
    cout<<endl;
}
void precompute(){

    FOR(2*maxN+10){
        int v=sqrt(i);
        if (v*v==i) squares.pb(i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}
