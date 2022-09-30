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
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2005;
int cnt[maxN];
void solve(){
    int n; cin>>n;
    FOR(1001) cnt[i]=0;
    int MAX=0;
    FOR(n){
        int v; cin>>v;
        MAX=max(v,MAX);
        cnt[v]++;
    }
    int ans=0;
    FOR(MAX+1)
        ans+=(cnt[i]>1 ? cnt[i] : 0);

    for (int i=1;i<=MAX;i++){
        int tot=0;
        for (int j=0;j<i;j++){
            int curr=0;
            int c=0;
            bool greater=false;
            for (int k=j,len=0;k<=MAX+i;k+=i,len++){
                int f=cnt[k];
                greater|=f>1;
                if (f==0){
                    if (len&1) curr+=(greater ? c: c-1);
                    else curr+=c;
                    c=0;
                    greater=false;
                    len=-1;
                }
                else c+=f;
            }
            tot+=curr;
        }
        ans=max(ans,tot);
    }
    print(ans);
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
    cin>>t;
    while (t--) solve();
}
