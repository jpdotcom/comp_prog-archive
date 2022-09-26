#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (int)1e9+7
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
int query(int a,int b,int tree[], int n){
    a+=n;
    b+=n;
    int s=0;
    while (a<=b){
        if (a&1) s+=tree[a++];
        if ((b&1)==0) s+=tree[b--];
        a/=2,b/=2;
    }
    return s;
}
void update(int a,int tree[], int i, int n){
    i+=n;
    tree[i]=a;
    i>>=1;
    while (i>=1){
        tree[i]=tree[2*i]+tree[2*i+1];
        i>>=1;
    }
}
void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int smallest[26];
    FOR(26) smallest[i]=i;
    int prev=-1;
    int curr=0;
    FOR(26){
        int big_sub=0;
        for (int j=prev+1;j<n;j++){
            int val=s[j]-97;
            for (int l=val;l<26;l++){
                val=min(val,smallest[l]);
            }
            if (val<=i){
                curr++;
                smallest[s[j]-97]=min(smallest[s[j]-97],val);
            }
            else if (val-k<=i){
                big_sub=max(big_sub,val-i);
                curr++;
            }
            else break;
        }
        for (int j=prev+1;j<curr;j++){
            if (j!=-1){
                smallest[s[j]-97]=min(smallest[s[j]-97],i);
                cout<<(char)(smallest[s[j]-97]+97);
            }
        }
        k-=big_sub;
        prev=curr-1;
    }
    cout<<endl;
}
void precompute(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
