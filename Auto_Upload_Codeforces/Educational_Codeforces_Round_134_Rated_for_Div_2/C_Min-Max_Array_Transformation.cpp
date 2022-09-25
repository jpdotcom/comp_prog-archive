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
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+10;
ll min_val[maxN];
ll max_val[maxN];
ll a[maxN];
ll b[maxN];
void solve(){

    int n; cin>>n;
    FOR(n) cin>>a[i];
    FOR(n) cin>>b[i];
    int i=0,j=0;
    while (i<n){
        while (j<n && b[j]<a[i]) j++;
        min_val[i]=b[j]-a[i];
        i++;
    }
    i=0,j=0;
    while (i<n){

        j=max(j,i);
        while (j+1<n && a[j+1]<=b[j]) j++;
        max_val[i]=b[j]-a[i];
        i++;
    }
    FOR(n) cout<<min_val[i]<<' ';
    cout<<endl;
    FOR(n) cout<<max_val[i]<<' ';
    cout<<endl;
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
    while (t--) solve();
}
