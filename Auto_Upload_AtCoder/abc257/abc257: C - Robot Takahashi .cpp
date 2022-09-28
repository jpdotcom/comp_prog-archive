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
const int maxN=2e5+1;
int a[maxN];
int cnt[maxN][2];
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vi b(n);
    map<int,int> c;
    FOR(n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin(),b.end());
    c[b[0]]=0;
    for (int i=1;i<n;i++){
        if (b[i]!=b[i-1]) c[b[i]]=c[b[i-1]]+1;
        else c[b[i]]=c[b[i-1]];
    }
    FOR(n){
        a[i]=c[a[i]];
        cnt[a[i]+1][s[i]-'0']++;
    }
    cnt[0][0]=cnt[0][1]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<2;j++)
            cnt[i][j]+=cnt[i-1][j];
    int ans=max(cnt[n][0],cnt[n][1]);
    for (int i=1;i<n;i++){
        ans=max(ans,cnt[i][0]+cnt[n][1]-cnt[i][1]);
    }
    print(ans);

}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
