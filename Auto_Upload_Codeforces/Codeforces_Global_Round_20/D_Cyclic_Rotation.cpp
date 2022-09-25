#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<long long> vi;
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
const int maxN=2e5+1;
int a[maxN];
int b[maxN];
map<int,int> cnt;
void solve(){
    int n;
    cin>>n;
    FOR(n) cin>>a[i];
    FOR(n) cin>>b[i];
    cnt.clear();
    int i=n-1,j=n-1;
    while (i>=0 || j>=0){
        if (j>=1 && b[j]==b[j-1]){
            if (cnt.find(b[j]) == cnt.end()) cnt[b[j]]=0;
            cnt[b[j]]++;
            j--;
        }
        else if (i>=0 && j>=0 && b[j]==a[i]){
            i--;
            j--;
        }
        else{
            if (cnt.find(a[i])==cnt.end() || cnt[a[i]]==0){
                print("NO");
                return;
            }
            else{
                cnt[a[i]]--;
                i--;
            }
        }
    }
    print("YES");
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
