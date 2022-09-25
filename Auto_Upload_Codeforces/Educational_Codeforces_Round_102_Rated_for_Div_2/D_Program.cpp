#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
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
const int maxN=2e5+1;
pi t[2*maxN];
int n;
int prefix[maxN];
void update(int i, int val){
    for (i+=(n+1),t[i].F=t[i].S=val,i>>=1;i>=1;i>>=1){
        t[i].F=min(t[i<<1].F,t[(i<<1)|1].F);
        t[i].S=max(t[i<<1].S,t[(i<<1)|1].S);
    }
}
pi query(int a, int b){
    pi ans=mp(1e9+7,-1e9+7);
    for (a+=n+1,b+=n+1;a<=b;a>>=1,b>>=1){
        if (a&1){
            ans.F=min(t[a].F,ans.F);
            ans.S=max(t[a].S,ans.S);
            a++;
        }
        if ((b&1)==0){
            ans.F=min(t[b].F,ans.F);
            ans.S=max(t[b].S,ans.S);
            b--;
        }
    }
    return ans;
}
void solve(){
    int m; cin>>n>>m;
    int sum=0;
    string s; cin>>s;
    prefix[0]=0;
    update(0,0);
    FOR(n){
        sum+=(s[i]=='+' ? 1 : -1);
        update(i+1,sum);
        prefix[i+1]=sum;
    }
    FOR(m){
        int a,b; cin>>a>>b;
        pi q1=query(0,a-1);
        ll min_val=q1.F,max_val=q1.S;
        if (b!=n){
            pi q2=query(b+1,n);
            ll sub=prefix[b]-prefix[a-1];
            min_val=min(min_val,q2.F-sub);
            max_val=max(max_val,q2.S-sub);
        }
        print(max_val-min_val+1);
    }
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
    while (t--){
        solve();
    }
}
