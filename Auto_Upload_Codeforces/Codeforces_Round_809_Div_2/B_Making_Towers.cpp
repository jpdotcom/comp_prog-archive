#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+10;
int a[maxN];
int cnt[maxN];
int ans[maxN];
int dist[maxN];
void solve(){
    int n; cin>>n;
    FOR(n+1) cnt[i]=dist[i]=ans[i]=0;
    FOR(n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    FOR(n){
        if (ans[a[i]]==0){
            ans[a[i]]=1;
            dist[a[i]]=i;
        }
        else{
            int d=i-dist[a[i]];
            ans[a[i]]+=(d==1 || d&1);
            dist[a[i]]=i;
        }
    }
    FOR(n){
        cout<<ans[i+1]<<' ';
    }
    cout<<endl;
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


