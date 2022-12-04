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
#define INF 1e9
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
#define all(a) a.begin(),a.end()
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6;
int a[maxN];
vector<int> inv[maxN];
int used[maxN];
void solve(){
    int n,x; cin>>n>>x;
    if (n%x!=0){
        print(-1);
        return;
    }
    if (x==1 && n!=1){
        print(-1);
        return;
    }
    int out[n+1];
    FOR(n+1) out[i]=0;
    out[1]=x;
    out[n]=1;
    int prev=x;
    while (prev!=n){
        for (int j=2;j*prev<=n;j++){
            int nxt=j*prev;
            if (n%nxt==0){
                out[prev]=nxt;
                prev=nxt;
                break;
            }
        }
    }
    FOR(n)
        if (!out[i+1]) out[i+1]=i+1;
    FOR(n) cout<<out[i+1]<<' ';
    cout<<endl;

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
