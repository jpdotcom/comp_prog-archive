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
const int maxN=1e6+2;
int a[maxN];
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    set<char> v={'a','e','i','o','u'};
    FOR(n+1) a[i]=0;
    FOR((int)s.size()){
        if (v.find(s[i])!=v.end()){
            a[0]+=1;
            a[i]+=1;
        }
    }
    a[0]&=1;
    for (int i=1;i<n;i++){
        a[i]=(a[i]+a[i-1])&1;
    }
    int i=0;
    int j=n-1;
    vi out(n);
    for (int k=n-1;k>=0;k--){
        if (a[k]^1){
            out[j]=s[k];
            j--;
        }
        else{
            out[i]=s[k];
            i++;
        }
    }
    for (char c: out) cout<<c;
    cout<<endl;
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
