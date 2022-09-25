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
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    int mx=-1*INF;
    int j;
    FOR(n){
        cin>>a[i];
        if (a[i]>mx){
            mx=a[i];
            j=i;
        }
    }
    bool ok=true;
    FOR(j-1){
        if (a[i]>a[i+1]) ok=false;
    }
    for (int i=j;i<n-1;i++){
        if (a[i]<a[i+1]) ok=false;
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
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}
