#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for (int i=0;i<a;i++)
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
#define INF (1e9)
#define endl '\n'
#define MOD ((int)998244353)
using namespace std;
const int maxN=1e6;
string s;
bool comp(int a,int b){
    return (s[b-1]>s[a-1]) || (s[b-1]==s[a-1] && a<b);
}
bool rev(int a, int b){
    return s[b-1]<s[a-1] || (s[b-1]==s[a-1] && a<b);
}
void solve(){
    cin>>s;
    int n=s.size();
    char f=s[0];
    char e=s[n-1];
    bool ok=f<=e;
    vector<int> indices;
    int cost=abs(f-e);
    for(int i=0;i<n;i++){
        if (ok){
            if (f<=s[i] && s[i]<=e) indices.pb(i+1);
        }
        else{
            if (e<=s[i] && s[i]<=f) indices.pb(i+1);
        }
    }
    if (ok) sort(indices.begin(),indices.end(),comp);
    else sort(indices.begin(),indices.end(),rev);
    cout<<cost<<' '<<indices.size()<<endl;
    for (int x: indices) cout<<x<<' ';
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
    while (t--) solve();
}
