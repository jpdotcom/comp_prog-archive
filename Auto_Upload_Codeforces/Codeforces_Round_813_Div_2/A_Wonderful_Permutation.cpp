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
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=1e5+1;
int a[maxN];
int b[maxN];
void solve(){
    map<int,int>cnt;
    int n,k; cin>>n>>k;
    FOR(n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    FOR(k) cnt[b[i]]++;
    FOR(k) cnt[a[i]]--;
    int ans=0;
    for (int i=k;i<n;i++){
        if (cnt[a[i]]>0){
            ans++;
            cnt[a[i]]--;
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
    cin>>t;
    while (t--)
    {
        solve();
    }
}
