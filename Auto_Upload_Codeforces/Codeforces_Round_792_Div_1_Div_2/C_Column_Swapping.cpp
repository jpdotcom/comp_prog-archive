#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
void solve(){
    int col1=-1,col2=-1;
    int n,m;cin>>n>>m;
    vector<vi> vals;
    FOR(n){
        vi c(m);
        for (int j=0;j<m;j++){
            cin>>c[j];
        }
        vals.pb(c);
    }
    FOR(n){
        vi svals(m);
        for (int j=0;j<m;j++){
            svals[j]=vals[i][j];
        }
        sort(svals.begin(),svals.end());
        int cnt=0;
        for (int j=0;j<m;j++){
            if (svals[j]!=vals[i][j]){
                cnt++;
                if (cnt==3){
                    print(-1);
                    return;
                }
                if (col1==-1) col1=j;
                else if (col2==-1) col2=j;
                else{
                    if ((col1!=j && col2!=j)){
                        print(-1);
                        return;
                    }
                }
            }
        }
    }
    if (col1==-1){
        cout<<1<<' '<<1<<endl;
        return;
    }
    for (int i=0;i<n;i++) swap(vals[i][col1],vals[i][col2]);
    for (int i=0;i<n;i++){
        for (int j=1;j<m;j++){
            if (vals[i][j]<vals[i][j-1]){
                print(-1);
                return;
            }
        }
    }
    cout<<col1+1<<' '<<col2+1<<endl;
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
