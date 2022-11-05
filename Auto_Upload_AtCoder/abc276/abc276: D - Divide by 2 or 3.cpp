#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define INF ((int)1e9)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>(s))&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e5+1;
void solve(){
    int n; cin>>n;
    set<int> left;
    vector<pi> times(n);
    int min2=INF,min3=INF;
    for (int i=0;i<n;i++){
        int a; cin>>a;
        int c=0;
        while (a%2==0){
            c++;
            a/=2;
        }
        times[i].F=c;
        min2=min(min2,c);
        c=0;
        while (a%3==0){
            c++;
            a/=3;
        }
        min3=min(min3,c);
        times[i].S=c;
        left.insert(a);
    }
    if (left.size()>1) print(-1);
    else{
        int ans=0;
        FOR(n){
            ans+=times[i].F+times[i].S-min3-min2;
        }
        print(ans);
    }
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cout<<setprecision(15);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    int i=0;
    while (t--){
        //cout<<"Case #" << (i+1) << ": ";
        solve();
        ++i;
    }
}

