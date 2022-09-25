#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a) for(int i=0;i<a;i++)
#define mp(a,b) make_pair(a,b)
#define all(a)  a.begin(),a.end()
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
//#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define MOD ((ll)1e9+7)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
void solve(){
    ll a=1;
    ll b=2;
    for (int i=0;i<50;++i){
        ll d1,d2;
        cout<<"? "<<a<<' '<<b<<endl;
        cin>>d1;
        cout<<"? "<<b<<' '<<a<<endl;
        cin>>d2;
        if (d1==-1 || d2==-1){
             cout<<"! "<<a<<endl;
             return;
        }
        else if (d1!=d2){
            cout<<"! "<<d1+d2<<endl;
            return;
        }
        a++,b++;
    }
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    int i=1;
    while (t--)
    {
        solve();
        ++i;
    }
}
