#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll a, ll b, ll p){
    ll ans=1;
    a%=p;  
    while(b){
        if(b&1)
            ans=(ans*a)%p;
        b/=2;
        a=(a*a)%p;
    }
    return ans;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
const int maxN=21;
char mat[maxN][maxN];
int seen[maxN][maxN];
void solve(){
    int n,m,k; cin>>n>>m>>k;
    FOR(n){
        string s; cin>>s;
        for (int j=0;j<m;j++){
            mat[i][j]=s[j];
            seen[i][j]=0;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int l=k;l<min(n,m);l++){
                int r=i,c=j;
                int tot=0;
                vector<pi>add;
                for (int p=0;p<=l && r<n && c<m && mat[r][c]=='*';p++,tot++){
                    add.pb(make_pair(r++,c++));
                }
                if (tot!=l+1) continue;
                r--,c--;
                for (int p=0;p<l && r>0 && c<m-1 && mat[r-1][c+1]=='*'; p++,tot++){
                    add.pb(make_pair(--r,++c));
                }
                if (tot!=2*l+1) continue;

                for (pi x: add){
                    seen[x.F][x.S]=true;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (mat[i][j]=='*' && !seen[i][j]){
                print("NO");
                return;
            }
        }
    }
    print("YES");
}   
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
     
}
