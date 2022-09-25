#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a,n) for (int a=0;a<n;a++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF (1e9)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1e6+1;
int arr[maxN];
void solve(){

    int n; cin>>n;
    FOR(i,n) cin>>arr[i];
    int me=(arr[n-1]  & 1 ? INF : arr[n-1]),mo=(arr[n-1] & 1 ? arr[n-1] : INF);
    bool ok=true;
    for (int i=n-2;~i;i--){
        if (!(arr[i]&1)){
            if (me<arr[i]) ok=false;
            me=min(arr[i],me);
        }
        else{
            if (mo<arr[i]) ok=false;
            mo=min(arr[i],mo);
        }
    }
    if (ok) print("Yes");
    else print("No");
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
