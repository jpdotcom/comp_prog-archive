#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
vi compress(string s){
    vi vals;
    int cnt=1;
    for (int i=1;i<s.size();i++){
        if (s[i]!=s[i-1]){
            vals.pb(cnt);
            cnt=1;
        }
        else cnt++;
    }
    if (cnt) vals.pb(cnt);
    return vals;
}
void solve(){
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int cnt=1;
    vi v1=compress(s);
    vi v2=compress(t);
    if (v1.size()!=v2.size() || s[0]!=t[0]){
        print(-1);
        return;
    }
    else{
        ll ans=0;
        for (int i=0;i<v1.size();i++){
            ll diff=abs(v1[i]-v2[i]);
            if (i!=v1.size()-1){
                if (v1[i]>v2[i]) v1[i+1]+=v1[i]-v2[i];
                else v1[i+1]-=v2[i]-v1[i];
            }
            ans+=diff;
        }
        print(ans);
    }
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
