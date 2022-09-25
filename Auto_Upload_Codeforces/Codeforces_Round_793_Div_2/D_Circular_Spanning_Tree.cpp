#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
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
#define INF ((ll)1e18+7)
#define endl '\n'
#define MOD ((int)998244353)
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s; cin>>s;
    int cnt=0;
    FOR(n) cnt+=(s[i]=='1');
    if (cnt&1 || cnt==0){
        print("NO");
        return;
    }
    print("YES");
    int idx=0;
    int tc=0;
    vector<pair<int,int>> out;
    FOR(n){
        if (s[i]=='1'){
            idx=tc=(i+1)%n;
        }
    }
    idx++;
    idx%=n;
    int prev=idx;
    while (idx!=tc){
        if (s[idx]=='1'){
            out.pb(make_pair(tc+1,prev+1));
            prev=idx+1;
            idx++;
            prev%=n;
            idx%=n;
        }
        else{
            out.pb(make_pair(idx+1,(idx+1)%n+1));
            idx++;
            idx%=n;
        }
    }
    for (auto &x:out)
        cout<<x.F<<' '<<x.S<<endl;

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
