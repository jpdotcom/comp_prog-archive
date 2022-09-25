#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define INF 1e9
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
#define all(a) a.begin(),a.end()
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6;
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    set<string> sol={"aca","aa","aba","abca","acba","abbacca","accabba"};
    int ans=INF;
    for (int i=0;i<n;i++){

        for (int j=2;j<=7;j++){
            if (sol.find(s.substr(i,j))!=sol.end()){
                ans=min(ans,j);
            }
        }
    }
    if (ans==INF) print(-1);
    else print(ans);
}
void precompute(){

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}
