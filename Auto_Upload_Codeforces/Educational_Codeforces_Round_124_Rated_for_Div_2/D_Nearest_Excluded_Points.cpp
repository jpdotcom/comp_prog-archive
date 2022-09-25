#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
map<pi,int> dist;
map<pi,pi> ans;
int X[maxN];
int Y[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>X[i]>>Y[i];
    FOR(n){
        dist[mp(X[i],Y[i])]=INF;
    }
    queue<pi> q;
    int delta[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    FOR(n){
        bool ok=false;
        for (auto d: delta){
                if (dist.find(mp(X[i]+d[0],Y[i]+d[1]))==dist.end()){
                    ok=true;
                    ans[mp(X[i],Y[i])]=mp(X[i]+d[0],Y[i]+d[1]);
                    break;
                }
                
            }
        
        if (ok){
            dist[mp(X[i],Y[i])]=1;
            q.push(mp(X[i],Y[i]));
        }

    }
    while (q.size()){
        pi p=q.front();
        q.pop();
        int x=p.F;
        int y=p.S;
        for (auto d: delta){
                pi t=mp(x+d[0],y+d[1]);
                if (dist.find(t)!=dist.end() && dist[t]==INF){
                    dist[t]=dist[p]+1;
                    q.push(t);
                    ans[t]=ans[p];
                }
            
        }
    }
    FOR(n){
        int x=X[i],y=Y[i];
        pi a=ans[mp(x,y)];
        cout<<a.F<<' '<<a.S<<endl;
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
    while (t--)
    {solve();
    }
}
