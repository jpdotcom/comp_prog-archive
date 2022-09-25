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
int a[maxN];
unordered_map<int,int> cnt;
void solve(){
    int n,k; cin>>n>>k;
    cnt.clear();
    FOR(n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int i=1,j=1,s=-1*n+2*cnt[j];
    int l=1,r=n;
    while (j<=n){
        if (s>=k){
            if (r-l+1>j-i+1){
                r=j;
                l=i;
            }
            s-=2*cnt[i];
            if (i==j){
                j++;
                s+=2*cnt[j];
            }
            i++;
        }
        else{
            j++;
            s+=2*cnt[j];
        }
    }
    cout<<l<<' '<<r<<endl;
    int need=1,last=0;
    s=0;
    FOR(n){
        s+=((l<=a[i] && a[i]<=r) ? 1 : -1 );
        if (s==need && need!=k){
            cout<<last+1<<' '<<i+1<<endl;
            need++;
            last=i+1;
        }
    }
    cout<<last+1<<' '<<n<<endl;
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


