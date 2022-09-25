#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
string a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    int b=0;
    FOR(5){
        vi vals(n);
        for (int j=0;j<n;j++){
            int v=0;
            for (char c: a[j]){
                v+=((c-'a')==i);
            }
            vals[j]=(2*v-(int)a[j].size());
        }
        sort(vals.begin(),vals.end(),greater<int>());
        int s=0;
        int ans=0;
        for (int x: vals){
            if (s+x>0){
                s+=x;
                ans++;
            }
        }
        b=max(ans,b);
    }
    print(b);
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
