#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
void solve(){

    ll a,b,c; cin>>a>>b>>c;
    ll vals[3]={a,b,c};
    sort(vals,vals+3);
    a=vals[2],b=vals[1],c=vals[0];
    if (max(max(a,b),c)-min(min(a,b),c)==1) print((a+b+c)/3);
    else if (a/2>=(b+c)) print(b+c);
    else{
        ll ans=0;
        while (a-c>1){
            a-=2;
            if (b<c) swap(b,c);
            b--;
            ans++;
        }
        ans+=(a+b+c)/3;
        print(ans);
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}


