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
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)998244353);
using namespace std;
const int maxN=1e5+1;;
void solve(){
    int n; cin>>n;
    ll downAdd=n-1, rightAdd=n-1;
    string s; cin>>s;
    FOR(s.size()){
        downAdd-=(s[i]=='D');
        rightAdd-=(s[i]=='R');
    }
    int idx=-1;
    for (int i=0;i<s.size();i++){
        if (s[i]!=s[0]){
            idx=i;
            break;
        }
    }
    if (idx==-1) print(n);
    else{
        ll ans=idx+(s[0]=='R'? rightAdd  : downAdd)+(rightAdd+1)*(downAdd+1);
        for (int i=idx+1;i<s.size();i++){
            if (s[i]=='D'){
                ans+=rightAdd+1;
            }
            else{
                ans+=downAdd+1;
            }
        }
        print(ans+1);
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
    while (t--) solve();
}
