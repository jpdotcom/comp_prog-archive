#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
#define bit(x,y) ((x>>y)&1)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
const int maxN=1e6+1;
ll a[maxN];
void solve(){
    int n;
    cin>>n;
    FOR(n) cin>>a[i];
    ll ans=0;
    for (int i=0;i<n;i+=2){
        ll lbrac=0,rbrac=0;
        for (int j=i+1;j<n;j++){
            if (j&1 && a[i]>=rbrac && a[j]>=lbrac){
                ll v=min(a[i]-rbrac+(rbrac!=0 ? 1 : 0),a[j]-lbrac + (lbrac!=0 ? 1: 0));
                ans+=v;
            }
            if (j&1){
                rbrac+=max(a[j]-lbrac,0LL);
                lbrac-=min(a[j],lbrac);
            }
            else lbrac+=a[j];
        }
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
