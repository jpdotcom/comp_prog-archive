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
int cnt[maxN];
ll d[maxN][maxN];
ll nCr[maxN][maxN];
void solve(){
    string n; cin>>n;
    int k; cin>>k;
    cnt[1]=0;
    if (k==0){
        print(1);
        return;
    }
    for (int i=2;i<1005;i++){
        cnt[i]=cnt[__builtin_popcount(i)]+1;
    }
    for (int i=0;i<1005;i++){
        nCr[0][i]=0;
        nCr[i][0]=1;
    }
    for (int i=1;i<1005;i++){
        for (int j=1;j<1005;j++){
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%MOD;
        }
    }
    d[0][0]=1;
    d[0][1]=0;
    reverse(n.begin(),n.end());
    for (int i=1;i<1005;i++) for (int j=1;j<1005;j++) d[i][j]=0;
    for (int i=1;i<=n.size();i++){
        for (int j=0;j<=1005;j++){
            if (n[i-1]=='0') d[i][j]=d[i-1][j];
            else{
                d[i][j]=(nCr[i-1][j]+(j-1>=0 ? d[i-1][j-1] : 0))%MOD;
            }
        }
    }
    ll ans=0;
    for (int i=1;i<1005;i++){
        if (cnt[i]==k-1){
            ans+=d[n.size()][i];
            if (i==1) ans--;
            ans%=MOD;
        }
    }
    print(ans);
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
