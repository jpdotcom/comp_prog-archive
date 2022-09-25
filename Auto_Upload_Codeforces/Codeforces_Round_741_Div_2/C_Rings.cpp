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
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    FOR(n){
        if (!(s[i]-'0')){
            if (n-(i+2)+1>=n/2){
                cout<<i+1<<' '<<n<<' '<<i+2<<' '<<n<<endl;
                return;
            }
            else{
                cout<<1<<' '<<i+1<<' '<<1<<' '<<i<<endl;
                return;
            }
        }
    }
    cout<<1<<' '<<n-1<<' '<<2<<' '<<n<<endl;
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
