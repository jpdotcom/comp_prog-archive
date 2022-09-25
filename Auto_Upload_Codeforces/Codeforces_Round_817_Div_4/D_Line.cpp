#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a,b) for (int a=0;a<=b;a++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF (1e18)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1e6+1;
char a[maxN];
void solve(){
    int n; cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    ll cval=0;
    for (int i=0;i<n;i++){
        if (a[i]=='L') cval+=i;
        else cval+=n-i-1;
    }
    priority_queue<ll> v;
    for (int i=0;i<n;i++){
        if (i<n/2 && a[i]=='L'){
            v.push(n-i-1-(i));
        }
        else if (i>=n/2 && a[i]=='R'){
            v.push(i-(n-i-1));
        }
    }
    for (int i=0;i<n;i++){

        if (v.size()){
            int q=v.top();v.pop();
            cval+=q;
        }
        cout<<cval<<' ';
    }
    cout<<endl;
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
    while (t--) solve();
}
