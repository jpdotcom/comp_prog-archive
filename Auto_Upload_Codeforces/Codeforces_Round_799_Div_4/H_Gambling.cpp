#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
vi idx[maxN];
int a[maxN];
pi b[maxN];
void solve(){
    int n; 
    cin>>n;
    FOR(n+1) idx[i].clear();
    FOR(n){
        cin>>a[i];
        b[i]=make_pair(a[i],i);
    }
    sort(b,b+n);
    ll v=0;
    a[b[0].S]=v;
    for (int i=1;i<n;i++){
        v+=(b[i].F!=b[i-1].F);
        a[b[i].S]=v;
    }
    FOR(n){
        idx[a[i]].pb(i);
    }
    ll ans=0,l=0,r=0;
    v=0;
    FOR(n){
        if (idx[i].size()>0){
        int s=1;
        int temp=1;
        int lm=idx[i][0],rm=idx[i][0];
        int lp=idx[i][0],rp=idx[i][0];
        for (int j=1;j<(int)idx[i].size();j++){
            if (temp-(idx[i][j]-idx[i][j-1]-1)+1>=1){
                rp=idx[i][j];
                temp=temp-idx[i][j]+idx[i][j-1]+2;
            }
            else{
                lp=idx[i][j];
                rp=idx[i][j];
                temp=1;
            }
            if (temp>s){
                lm=lp;
                rm=rp;
                s=temp;
            }
        }
        if (s>=v){
            ans=i;
            l=lm;
            r=rm;
            v=s;
        }
        }
    }
    int g=0;
    for (int i=0;i<n;i++){
        if (g==ans){
            cout<<b[i].F<<' ';
            break;
        }
        if (i!=n-1 && b[i].F!=b[i+1].F) g++;
    }
    cout<<l+1<<' '<<r+1<<endl;
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
    while (t--){
        solve();
    }
}
