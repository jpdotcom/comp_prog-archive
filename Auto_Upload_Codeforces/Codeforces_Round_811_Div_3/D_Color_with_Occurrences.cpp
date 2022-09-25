#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=100;
string a[maxN];
int ans[maxN];
pi trace[maxN];
map<string, int> has;
void solve(){
    string t;
    cin>>t;
    int n; cin>>n;
    has.clear();
    FOR(n){
        string q;cin>>q;
        a[i]=q;
        has[q]=i;
    }
    ans[0]=0;
    trace[0]=mp(0,0);
    for (int i=1;i<=t.size();i++){
        ans[i]=INF;
        for (int j=0;j<i;j++){
            for (int k=j;k<i;k++){
            if (ans[k]+1<ans[i] && has.find(t.substr(j,i-j))!=has.end()){
                trace[i]=mp(k,has[t.substr(j,i-j)]);
                ans[i]=ans[k]+1;
            }
            }
        }
    }
    if (ans[t.size()]>=INF){
        print(-1);
        return;
    }
    int idx=t.size();
    vector<pi> vals;
    while (idx!=0){
        vals.pb(mp(trace[idx].S+1,idx-a[trace[idx].S].size()+1));
        idx=trace[idx].F;
    }
    print(vals.size());
    for (int i=vals.size()-1;~i;i--){
        cout<<vals[i].F<<' '<<vals[i].S<<endl;
    }
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
    while (t--)
    {
        solve();
    }
}
