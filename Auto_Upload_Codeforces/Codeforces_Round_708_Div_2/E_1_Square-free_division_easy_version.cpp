#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1LL)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
const int maxP=1e7+1;
int a[maxN];
int primes[maxP];
int get_vals(int p){
    map<int,int> cnt;
    while (p!=1){
        cnt[primes[p]]^=1;
        p/=primes[p];
    }
    int ans=1;
    for (auto &it :cnt){
        ans*=pow(it.F,it.S);
    }
    return ans;
}
void solve(){
    int n,k; cin>>n>>k;
    set<int> seen;
    int ans=0;
    FOR(n) cin>>a[i];
    FOR(n){
        int v=get_vals(a[i]);
        if (seen.find(v)!=seen.end()){
            ans++;
            i--;
            seen.clear();
        }
        else seen.insert(v);
    }
    if (seen.size()) ans++;
    print(ans);
}
void precompute(){
    FOR(maxP) primes[i]=i;
    for (int i=2;i<=(int)sqrt(maxP);i++){
        if (primes[i]==i){
            for (int j=i*i;j<maxP;j+=i)
                if (primes[j]==j)
                    primes[j]=i;
        }
    }
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
