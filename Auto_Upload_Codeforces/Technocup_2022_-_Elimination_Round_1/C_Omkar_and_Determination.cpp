#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
const int maxN=2e5+10;
void solve(){
    int n,m; cin>>n>>m;
    vector<string> arr(n);
    FOR(n) cin>>arr[i];
    vi prefix(m);
    for (int j=0;j<m;j++){
        for (int i=0;i<n;i++){
            if (i!=0 && j!=0 && (arr[i-1][j]=='X' && arr[i][j-1]=='X')) prefix[j]++;
        }
        if (j!=0) prefix[j]+=prefix[j-1];
    }
    int q; cin>>q;
    FOR(q){
        int a,b; cin>>a>>b; a--,b--;
        print(((prefix[b]-prefix[a]) ? "NO" : "YES"));
    }
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
