#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e5+1;
int a[maxN];
void solve(){
    int n,q; cin>>n>>q;
    FOR(n) cin>>a[i];
    int l=0,r=n;
    char s[n];
    FOR(n) s[i]='0';
    while (l<=r){
        int m=l+(r-l)/2;
        vi idx;
        FOR(m){
            if (a[i]<=q){
                idx.pb(i);
            }
        }
        int c=0;
        for (int i=m,v=q;i<n;i++){
            if (v>=a[i]){
                idx.pb(i);
                c++;
            }
            else if (v>0){
                v--;
                idx.pb(i);
                c++;
            }
            else break;
        }
        if (c==n-m){
            r=m-1;
            FOR(n) s[i]='0';
            for (int x: idx) s[x]='1';
        }
        else l=m+1;
    }
    for (char c: s) cout<<c;
    print("");
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


