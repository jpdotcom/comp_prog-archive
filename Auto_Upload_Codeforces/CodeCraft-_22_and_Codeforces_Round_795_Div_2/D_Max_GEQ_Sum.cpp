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
const int maxN=2e5+5;
ll arr[maxN];
ll prefix[maxN];
ll suffix[maxN];
int n;
vi great(){
    stack<int> s;
    vector<int>out(n,n);
    FOR(n){
        while (s.size()>0 && arr[s.top()]<arr[i]){
            out[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return out;
}
vi lesser(){
    stack<int> s;
    vector<int>out(n,-1);
    for (int i=n-1;i>=0;i--){
        while (s.size()>0 && arr[s.top()]<arr[i]){
            out[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return out;
}
ll query(vector<ll> &tree,int a,int b,int n){
    a+=n,b+=n;
    ll ans=-1e18;
    while (a<=b){
        if (a&1) ans=max(ans,tree[a++]);
        if ((b&1)==0) ans=max(ans,tree[b--]);
        a/=2,b/=2;
    }
    return ans;
}
void update(vector<ll> &tree,int i, ll val,int n){
    i+=n;
    tree[i]=val;
    i>>=1;
    while (i>0){
        tree[i]=max(tree[2*i],tree[2*i+1]);
        i>>=1;
    }
}
void solve(){
    cin>>n;
    FOR(n){
        cin>>arr[i];
        prefix[i]=arr[i]+ ((i==0) ? 0 : prefix[i-1]);
    }
    for (int i=n-1;i>=0;i--){
        suffix[i]=arr[i]+((i==n-1) ? 0 : suffix[i+1]);
    }
    vi leftM=lesser(),rightM=great();
    vector<ll> leftT(2*n+1,-1e15),rightT(2*n+1,-1e15);
    FOR(n){
        update(leftT,i,suffix[i],n);
        update(rightT,i,prefix[i],n);
    }
    bool flag=true;
    for (int i=0;i<n;i++){
        ll l=query(leftT,leftM[i]+1,i-1,n)-suffix[i];
        ll r=query(rightT,i+1,rightM[i]-1,n)-prefix[i];
        if (max(l,r)>0){
            flag=false;
        }
    }
    if (flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
