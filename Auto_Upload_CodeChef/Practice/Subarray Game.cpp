#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(n) for(int i=0;i<(int)(n);i++)
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
#define INF (1e8)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=1e6+1;
int a[maxN];
void solve(){

    int ic=0,dc=0;
    int n; cin>>n;
    FOR(n) cin>>a[i];
    int nim=0;
    for (int i=1;i<n;i++){
        if (a[i]>a[i-1]){
            ic++;
            if (dc || i==1){
                ic++;
                nim^=max(0,dc-2);
            }
            dc=0;
        }
        else{
            dc++;
            if (ic || i==1){
                nim^=max(0,ic-2);
                dc++;
            }
            ic=0;
        }
    }
    nim^=max(0,ic-2);
    nim^=max(0,dc-2);
    if (nim) print("Alice");
    else print("Bob");
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
