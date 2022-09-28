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
const int maxN=1005;
string a[maxN];
void solve(){
    int n; cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    bool ok=true;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==j) continue;
            if (a[i][j]=='D' && a[j][i]!='D') ok=false;
            if (a[i][j]=='W' && a[j][i]!='L') ok=false;
            if (a[i][j]=='L' && a[j][i]!='W') ok=false;
        }
    }
    if (ok) print("correct");
    else print("incorrect");
}
void precompute(){
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    while (t--) solve();
}
