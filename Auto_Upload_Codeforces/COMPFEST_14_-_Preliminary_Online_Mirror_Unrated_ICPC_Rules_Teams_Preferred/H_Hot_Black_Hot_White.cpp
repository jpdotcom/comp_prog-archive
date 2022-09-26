#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define INF ((int)1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e5+10;
int a[maxN];
int n; 
pair<int,vector<int>> can(int z){
    vector<int> b(n);
    vector<int> cnt(3,0);
    int sub=(z==1 ?  2 : z/2);
    FOR(n){
        b[i]=((a[i]-sub)+3)%3;
        b[i]=(b[i]+3)%3;
        cnt[b[i]]++;
    }
    if (cnt[1]==0 || cnt[2]==0){
        if (cnt[0]>n/2){
            return mp(0,vector<int>());
        }
        else{
            int other=(cnt[1]==0 ? 2 : 1);
            vector<int> out(n,0);
            int left=n/2;
            FOR(n){
                if (left==0) break;
                if (b[i]==other){
                    out[i]=1;
                    left--;
                }
            }
            return mp(1,out);
        }
    }
    else{
        if (cnt[1]!=n/2 && cnt[2]!=n/2){
            return mp(0,vector<int>());
        }
        vector<int> out(n,0);
        int need=(cnt[1]==n/2 ? 1: 2);
        FOR(n)
            if (b[i]==need)
                out[i]=1;
        return mp(1,out);
    }
}
void solve(){
    cin>>n;
    FOR(n){
        ll v; cin>>v;
        v*=v;
        v%=3;
        a[i]=v;
    }
    FOR(3){
        pair<int,vector<int>> v=can(i);
        if (v.F){
            print(i);
            for (auto x: v.S){
                cout<<x;
            }
            cout<<endl;
            return;
        }
    }
    cout<<-1<<' ';
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    //cin>>t;
    while (t--){
        solve();
    }
}

