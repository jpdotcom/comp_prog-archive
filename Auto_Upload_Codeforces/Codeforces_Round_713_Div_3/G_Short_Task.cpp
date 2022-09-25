#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e7+1;
int ans[maxN];
int prime[maxN];
ll pmult(int n){
    ll ans=1;
    int cnt=0;
    int p=-1;
    while (n!=1){
        if (prime[n]!=p){
            if (p!=-1){
                ans*=(pow(p,cnt+1)-1)/(p-1);
            }
            p=prime[n];
            cnt=1;
        }
        else cnt++;
        n/=prime[n];
    }
    if (cnt!=0){
        ans*=(pow(p,cnt+1)-1)/(p-1);
    }
    return ans;

}
void solve(){
    int c; cin>>c;
    print(ans[c]);
}
void precompute(){
    FOR(maxN) prime[i]=i;
    for (int i=2;i<sqrt(maxN)+1;i++){
        if (prime[i]==i){
        for (int j=i*i;j<maxN;j+=i){
            if (prime[j]==j) prime[j]=i;
        }
        }
    }
    FOR(maxN) ans[i]=-1;
    for (int i=1;i<maxN;i++){
        ll v=pmult(i);
        if (v<maxN && ans[v]==-1) ans[v]=i;
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


