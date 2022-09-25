#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
int get_sum(char c){
    if (c=='R' || c=='D') return 1;
    return -1;
}
pi inter(pi p1, pi p2,int mx){
    int v1=max(p1.F,p2.F);
    int v2=min(p1.S,p2.S);
    if (v2-v1+1<=0 || p2.F>p2.S || p1.F>p1.S || p1.F<1 || p2.F<1 || p2.S>mx || p1.S>mx) return make_pair(-1,-1);
    return make_pair(v1,v2);
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s; cin>>s;
    pi ans=make_pair(1,1);
    pi p1=make_pair(1,m), p2=make_pair(1,n);
    int cs1=0,cs2=0;
    for (int i=0;i<(int)s.size();i++){
        
        if (s[i]=='L' || s[i]=='R'){
            cs1+=get_sum(s[i]);
            if (cs1<0) p1=inter(p1,make_pair(-1*cs1+1,m),m);
            else p1=inter(p1,make_pair(1,m-cs1),m);
            if (p1.F==-1) break;
        }
        else{
            cs2+=get_sum(s[i]);
            if (cs2<0) p2=inter(p2,make_pair(-1*cs2+1,n),n);
            else p2=inter(p2,make_pair(1,n-cs2),n);
            if (p2.F==-1) break;
        }
        ans=make_pair(p1.F,p2.F);
    }
    cout<<ans.S<<' '<<ans.F<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
