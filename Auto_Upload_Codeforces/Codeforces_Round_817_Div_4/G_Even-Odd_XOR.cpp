#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(n) for(int i=0;i<(int)(n);i++)
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
void solve(){
    int n; cin>>n;
    if (n%4==0){
        FOR(n) cout<<i<<' ';
    }
    else if (n%4==1){
        cout<<0<<' ';
        for (int i=2;i<=n;i++) cout<<i<<' ';
    }
    else if(n%4==2){
        cout<<0<<' ';
        for (int i=3;i<n;i++) cout<<i<<' ';
        cout<<(1<<30)<<' '<<(1<<30)+2;
    }
    else{
        for (int i=1;i<=n;i++) cout<<i<<' ';
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
