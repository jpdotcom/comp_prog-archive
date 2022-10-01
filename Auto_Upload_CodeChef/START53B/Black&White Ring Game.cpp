#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e5+1;
int a[maxN];
int win[maxN];
map<int,int> c;
void solve(){
    int n; cin>>n;
    FOR(n) cin>>a[i];
    c.clear();
    if (a[0]==a[n-1]) c[a[0]]++;
    FOR(n-1){
        if (a[i]==(a[(i+1)%n])) c[a[i]]++;
    }
    int ans=min(c[0],c[1]);
    if ((ans&1)==0) print("Bob");
    else print("Alice");
 
}
void precompute(){

    win[0]=0;
    win[1]=1;
    win[2]=1;
    for (int i=3;i<maxN;i++){
        win[i]|=(win[i-1]^1);
        win[i]|=(win[i-2]^1);
    }
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    cin>>t;
    while (t--) solve();
}
