#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+10;
bool rev(int a, int b){
    return a>b;
}
void solve(){
    int n; cin>>n;
    vector<vector<int>> a(1);
    vector<vector<int>> b(1);
    FOR(n){
        int v; cin>>v;
        a[0].pb(v);
    }
    FOR(n){
        int v; cin>>v;
        b[0].pb(v);
    }
    int ans=0;
    for (int i=30;i>=0;i--){
        vector<vector<int>> na;
        vector<vector<int>> nb;
        bool can=true;
        assert(a.size()==b.size());
        for (int j=0;j<a.size();j++){
            sort(a[j].begin(),a[j].end(),rev);
            sort(b[j].begin(),b[j].end());
        }
        vector<int> cnt(a.size(),0);
        vector<int> cnt2(a.size(),0);
        for (int j=0;j<a.size();j++){
            assert(a[j].size()==b[j].size());
            for (int k=0;k<a[j].size();k++){
                cnt[j]+=bit(a[j][k],i);
                cnt2[j]+=!(bit(b[j][k],i));
            }

        }
        for (int j=0;j<a.size();j++){
            if (cnt[j]==cnt2[j]){
                vector<int>pusha,pushb;
                for (int k=0;k<cnt[j];k++){
                    pusha.pb(a[j][k]-(1<<i));
                    pushb.pb(b[j][k]);
                }
                if (pusha.size()){
                    na.push_back(pusha);
                    nb.push_back(pushb);
                }
                pusha.clear(),pushb.clear();
                for (int k=cnt[j];k<a[j].size();k++){
                    pusha.pb(a[j][k]);
                    pushb.pb(b[j][k]-(1<<i));
                }
                if (pusha.size()){
                    na.push_back(pusha);
                    nb.push_back(pushb);
                }
            }
            else{
                can=false;
                break;
            }
        }
        if (can){
            a=na;
            b=nb;
            ans+=(1<<i);
        }
        else{
            for (int j=0;j<a.size();j++){
                for (int k=0;k<a[j].size();k++){
                    if (a[j][k]>=(1<<i)) a[j][k]-=(1<<i);
                    if (b[j][k]>=(1<<i)) b[j][k]-=(1<<i);
                }
            }
        }
    }
    print(ans);
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

