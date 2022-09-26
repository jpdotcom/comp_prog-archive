#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<char,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
const int maxN=1e6+1;
ll t[maxN];
int n;
string s;
ll get(int a, char c){
    if (2*a>=n){
        if (c=='?') return 2;
        else return 1;
    }
    if (c=='?'){
        return t[2*a]+t[2*a+1];
    }
    else if (c=='1') return t[2*a];
    else return t[2*a+1];
}
void update(int a, char c){
    t[a]=get(a,c);
    a>>=1;
    while (a>=1){
        t[a]=get(a,s[n-a-1]);
        a>>=1;
    }
}
void solve(){
    cin>>n>>s;
    n=pow(2,n);
    FOR(n+1) t[i]=0;
    FOR(n){
        update(n-i-1,s[i]);
    }
    int q; cin>>q;
    FOR(q){
        int a;
        char c;
        cin>>a>>c;
        s[a-1]=c;
        update(n-a,c);
        print(t[1]);
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
    while (t--){
        solve();
    }
}


