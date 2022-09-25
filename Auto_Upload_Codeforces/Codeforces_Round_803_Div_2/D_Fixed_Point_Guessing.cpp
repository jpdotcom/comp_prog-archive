#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
//#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
void solve(){
    int n; cin>>n;
    int l=1,r=n;
    int ans=-1;;
    while (l<=r){
        int m=l+(r-l)/2;
        cout<< "? " << l <<' ' << m << endl;
        vi vals(m);
        int s=(m-l+1)&1;
        int t=0;
        FOR(m-l+1){
            cin>>vals[i];
            t^=(vals[i]<l || vals[i]>m);
        }
        if (s^t) r=m-1;
        else l=m+1;
    }
    cout<<"! " << l<<endl;
    return;
}
void precompute(){
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--)
    {solve();
    }
}
