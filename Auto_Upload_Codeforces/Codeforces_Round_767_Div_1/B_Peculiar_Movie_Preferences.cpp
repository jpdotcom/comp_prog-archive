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
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
string a[maxN];
unordered_map<string,int> cnt;
void solve(){
    int n; cin>>n;
    cnt.clear();
    FOR(n){
        cin>>a[i];
        cnt[a[i]]=i+1;
    }
    bool ok=false;
    FOR(n){
        string s=a[i];
        string prev=a[i];
        reverse(s.begin(),s.end());
        ok|=(s==prev || (cnt[s]>i+1));
        string t=prev.substr(0,prev.size()-1);
        reverse(t.begin(),t.end());
        ok|=(cnt[t]>i+1);
        for (int j=0;j<26;j++){
            ok|=(cnt[(char)(j+97) + s]>i+1);
        }
    }
    if (ok) print("YES");
    else print("NO");
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


