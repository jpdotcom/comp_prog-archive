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
#define MOD ((int)1e9+7)
using namespace std;
void solve(){
    int n,m; cin>>n>>m;
    string s;
    string t(n,'?');
    cin>>s;
    vector<int> vals(m);
    FOR(m) cin>>vals[i];
    int i=0;
    int j=0;
    for (int x: vals){
        if (x-1+s.size()-1>=i){
            if (x-1>=i){
                i=x-1;
                j=0;
            }
            else{
                j=s.size()-1-((x-1+s.size()-1-i));
            }
            for (i,j;j<s.size();i++,j++){
                t[i]=s[j];
            }
        }
    }
    t=s+"#"+t;
    vector<int> pf(t.size(),0);
    for (int i=1;i<t.size();i++){
        int j=pf[i-1];
        while (j>0 && t[i]!=t[j])
            j=pf[j-1];
        if (t[i]==t[j]) j++;
        pf[i]=j;
    }
    for (int x: vals){
        int idx=x-1+s.size()+s.size();
        if (pf[idx]!=s.size()){
            print("0");
            return;
        }
    }
    ll ans=1;
    for (int i=s.size()+1;i<t.size();i++){
        if (t[i]=='?'){
            ans*=26;
            ans%=MOD;
        }
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
