#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long,long> pi;
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
const int maxN=1e6+1;
string dp[maxN];
void solve(){
    int n; cin>>n;
    int vals[9];
    int m=1e9+9;
    FOR(9){
        cin>>vals[i];
        m=min(m,vals[i]);
    }
    int l=n/m;
    string ans="";
    for (int i=l;i>0;i--){
        int dig=0;
        for (int j=0;j<9;j++){
            if (n>=vals[j] && (n-vals[j])/m>=(i-1)) dig=j;
        }
        n-=vals[dig];
        cout<<dig+1;
    }

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
