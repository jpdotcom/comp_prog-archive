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
void solve(){
    int n; cin>>n;
    vi left;
    vi right;
    int j;
    FOR(ceil(n/2.0)){
        left.pb(i+1);
        j=i+1;
    }
    for (j++;j<=n;j++){
        right.pb(j);
    }
    bool other=1;
    if (left.size()>right.size()){
        cout<<left[left.size()-1]<<' ';
        left.pop_back();
        other=0;
    }
    for (int i=left.size()-1,j=0;j<right.size(),i>=0;i--,j++){
        if (other) cout<<right[j]<<' '<<left[i]<<' ';
        else cout<<left[i]<<' '<<right[j]<<' ';
    }
    cout<<endl;
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
    while (t--) solve();
}
