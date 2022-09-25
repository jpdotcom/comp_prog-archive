#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for (int i=0;i<a;i++)
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
#define MOD ((int)998244353)
using namespace std;
const int maxN=1e6;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int d1=a,d2=abs(b-c)+c;
    if (d1>d2) print(2);
    else if (d1<d2) print(1);
    else print(3);
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
