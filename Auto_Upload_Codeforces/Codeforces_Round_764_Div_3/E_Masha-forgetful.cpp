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
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1005;
string a[maxN];
int can[maxN];
string trace[maxN];
int len[maxN];
map<string,pi> fi;
void solve(){
    int n,m; cin>>n>>m;
    fi.clear();
    string t;
    FOR(m+1) can[i]=len[i]=false;
    FOR(n){
        cin>>a[i];
    }
    cin>>t;
    FOR(n){
        for (int k=0;k<m;k++){
        for (int j=2;j<4;j++){
            if (k+j-1<m){
            fi[a[i].substr(k,j)]=mp(i,k);
            }
        }
        }
    }
    can[0]=true;
    trace[0]="";
    len[0]=0;
    for (int i=2;i<=m;i++){
        if (i-2>=0){
            string q=t.substr(i-2,2);
            if (fi.find(q) != fi.end() && can[i-2]){
                can[i]=true;
                trace[i]=q;
                len[i]=2;
            }
        }
        if (i-3>=0){
            string q=t.substr(i-3,3);
            if (fi.find(q)!=fi.end() && can[i-3]){
                can[i]=true;
                trace[i]=q;
                len[i]=3;
            }
        }
    }

    if (!can[m]){
        print(-1);
        return;
    }
    vector<vi> vals;
    int idx=m;
    while (idx!=0){
        vi push={fi[trace[idx]].S+1,fi[trace[idx]].S+len[idx],fi[trace[idx]].F+1};
        vals.pb(push);
        idx-=len[idx];
        
    }
    print(vals.size());
    for (int i=vals.size()-1;~i;i--){
        cout<<vals[i][0]<<' '<<vals[i][1]<<' '<<vals[i][2]<<endl;
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
    while (t--){
        solve();
    }
}

