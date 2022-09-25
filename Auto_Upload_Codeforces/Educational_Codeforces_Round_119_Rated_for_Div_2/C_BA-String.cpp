#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2005;
void solve(){
    ll n,k,x; cin>>n>>k>>x;
    x--;
    string s; cin>>s;
    vector<char> out;
    ll f=0;
    for (int j=n-1;j>=0;j--){
        if (s[j]=='a'){
            FOR(x%(f+1)) out.pb('b');
            x/=(f+1);
            f=0;

            out.pb('a');
        }
        else{
            f+=k;
        }
    }
    if (f!=0){
        FOR(x%(f+1)) out.pb('b');
    }
    reverse(out.begin(),out.end());
    for (char c:out) cout<<c;
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
    while (t--){
        solve();
    }
}


