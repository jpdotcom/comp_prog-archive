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
const int maxN=1e5+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    FOR(n){
        cin>>a[i];
    }
    reverse(a,a+n);
    bool ok=true;
    int idx=-1;
    FOR(n){
        if (a[i]==1 && idx==-1){
            idx=i;
        }
        else if (a[i]==1 && idx!=-1){
            print("NO");
            return;
        }
    }
    if (idx==-1){
        print("NO");
        return;
    }
    FOR(n){
        if (a[(idx+1)%n]-a[idx]<-1){
            ok = false;
        }
        idx+=1;
        idx%=n;
    }
    if (ok) print("YES");
    else print("NO");
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


