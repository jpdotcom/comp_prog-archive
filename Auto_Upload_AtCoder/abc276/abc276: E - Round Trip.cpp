#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
//#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
int h,w; 
pi p;
vector<vector<int>> valid;
vector<vector<int>> seen;
bool v(int v1,int v2){
    pi u=mp(v1,v2);
    return -1<u.F && u.F<h && -1<u.S && u.S<w && valid[u.F][u.S];
}
bool bfs(pi from, pi to){
    queue<pi> q;
    q.push(from);
    FOR(h)
        for (int j=0;j<w;j++)
            seen[i][j]=0;
    while (q.size()){
        pi u=q.front();
        q.pop();
        if (v(u.F+1,u.S) && !seen[u.F+1][u.S] && mp(u.F+1,u.S)!=p){
            q.push(mp(u.F+1,u.S));
            seen[u.F+1][u.S]=1;
        }
        if (v(u.F-1,u.S) && !seen[u.F-1][u.S]&& mp(u.F-1,u.S)!=p){
            q.push(mp(u.F-1,u.S));
            seen[u.F-1][u.S]=1;
        }
        if (v(u.F,u.S-1) && !seen[u.F][u.S-1]&& mp(u.F,u.S-1)!=p){
            q.push(mp(u.F,u.S-1));
            seen[u.F][u.S-1]=1;
        }
        if (v(u.F,u.S+1) && !seen[u.F][u.S+1] && mp(u.F,u.S+1)!=p){
            q.push(mp(u.F,u.S+1));
            seen[u.F][u.S+1]=1;
        }
    }
    return seen[to.F][to.S];
}
void solve(){
    cin>>h>>w;
    valid=vector<vector<int>>(h,vector<int>(w,0));
    seen=vector<vector<int>>(h,vector<int>(w,0));
    for (int i=0;i<h;i++){
        string s; cin>>s;
        for (int j=0;j<s.size();j++){
            char c=s[j];
            if (c!='#') valid[i][j]=1;
            if (c=='S') p=mp(i,j);
        }
    }
    int ok=0;
    for (int i=-1;i<2;i++){
        for (int j=-1;j<2;j++){
            for (int k=-1;k<2;k++){
                for (int l=-1;l<2;l++){
                    if ((i!=0 && j!=0) || (k!=0 && l!=0)) continue;
                    pi t1=mp(p.F+i,p.S+j);
                    pi t2=mp(p.F+k,p.S+l);
                    if (t1!=p && t2!=p && t1!=t2 && v(t1.F,t1.S) && v(t2.F,t2.S)) ok|=bfs(t1,t2);
                }
            }
        }
    }
    if (ok) print("Yes");
    else print("No");
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
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
