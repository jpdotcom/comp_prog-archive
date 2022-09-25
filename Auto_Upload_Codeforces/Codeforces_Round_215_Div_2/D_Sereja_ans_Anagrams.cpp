#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
int power(long long x, unsigned int y, ll p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void precompute(){
}
const int maxN=2e5+1;
int arr[maxN];
map<int,int> cnt;
int get_val(int a,int s){
    if (cnt.find(a)!=cnt.end()){
        s+=(cnt[a]>0);
        cnt[a]--;
    }
    return s;
}
void solve(){
    ll n,m,p;
    cin>>n>>m>>p;
    FOR(n) cin>>arr[i];
    FOR(m){
        int val;
        cin>>val;
        if (cnt.find(val) == cnt.end()) cnt[val]=0;
        cnt[val]++;
    }
    vi ans;
    for (int i=0;i<p;i++){
        int s=0,st=-1*p+i;
        for (int j=i,l=0;(l<m && j<n);l++,j+=p){
            s=get_val(arr[j],s);
        }
        if (s==m){
            ans.pb(i+1);
        }
        for (ll j=i+m*p,k=i;j<n;j+=p,k+=p){
            if (cnt.find(arr[k])!=cnt.end()){
                cnt[arr[k]]++;
                s-=(cnt[arr[k]]>0);
            }
            s=get_val(arr[j],s);
            st=k;
            if (s==m){
                ans.pb(k+p+1);
            }
        }
        for (int j=st+p,l=0;(l<m && j<n);l++,j+=p){
            if (cnt.find(arr[j])!=cnt.end()) cnt[arr[j]]++;
        }
    }
    sort(ans.begin(),ans.end());
    print(ans.size());
    for (int x:ans) cout<<x<<' ';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(25);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

