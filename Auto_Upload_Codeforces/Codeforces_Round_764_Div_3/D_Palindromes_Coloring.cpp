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
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
void solve(){
    int n,k; 
    cin>>n>>k;
    string s; cin>>s;
    int doubles=0;
    int singles=0;
    int cnt[26];
    FOR(26) cnt[i]=0;
    FOR(s.size()){
        cnt[s[i]-'a']++;
    }
    FOR(26){
        doubles+=cnt[i]/2;
        singles+=cnt[i]&1;
    }
    if (doubles==0){
        print(1);
        return;
    }
    int mx=2*(doubles/k);
    while (2*((doubles-1)/k)==mx && singles<k){
        singles+=2;
        doubles--;
    }
    print(mx+(singles/k>=1 ? 1 : 0));
    return;

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
