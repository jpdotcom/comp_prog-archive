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
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
void solve(){
    string s,t; cin>>s>>t;
    vector<pi> v1;
    vector<pi> v2;
    int a=s[0]-'a',b=1;
    for (int i=1;i<s.size();i++){
        if (s[i]-'a'!=a){
            v1.pb(mp(a,b));
            a=s[i]-'a';
            b=1;
        }
        else b++;
    }
    if (b>0) v1.pb(mp(a,b));
    a=t[0]-'a',b=1;
    for (int i=1;i<t.size();i++){
        if (t[i]-'a'!=a){
            v2.pb(mp(a,b));
            a=t[i]-'a';
            b=1;
        }
        else b++;
    }
    if (b>0) v2.pb(mp(a,b));
    int ok=(v1.size()==v2.size());
    for (int i=0;i<min(v1.size(),v2.size());i++)
        ok&=(v1[i].F==v2[i].F && (v1[i].S==v2[i].S || (v1[i].S>=2 && v1[i].S<v2[i].S)));
    if (ok) print("Yes");
    else print("No");

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
    while (t--){
        solve();
    }
}


