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
const int maxN=1005;
int rep[maxN];
int siz[maxN];

int frep(int a){
    if (rep[a]==a) return a;
    int r=frep(rep[a]);
    rep[a]=r;
    return r;
}
int un(int a, int b){
    int r1=frep(a);
    int r2=frep(b);
    if (r1==r2) return 0;
    if (siz[r1]<siz[r2]) swap(r1,r2);
    int new_size=siz[r1]+siz[r2];
    rep[r2]=r1;
    siz[r2]=siz[r1]=new_size;
    return 1;
}
void solve(){

    int n,d;
    cin>>n>>d;
    vector<pi> arr;
    FOR(d){
        int a,b; cin>>a>>b;
        arr.pb(make_pair(a,b));
        for (int j=0;j<n+1;j++){
            rep[j]=j,siz[j]=1;
        }
        vi s;
        int ee=i+1;
        for (int j=0;j<(int)arr.size();j++){
            un(arr[j].F,arr[j].S);
        }
        for (int j=1;j<=n;j++){
            if (frep(j)==j){
                s.pb(siz[j]-1);
                ee-=(siz[j]-1);
            }
        }
        sort(s.begin(),s.end());
        int ans=s[(int)s.size()-1];
        for (int j=s.size()-2;j>=0;j--){
            if (ee--) ans+=s[j]+1;
            else break;
        }
        print(ans);
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
