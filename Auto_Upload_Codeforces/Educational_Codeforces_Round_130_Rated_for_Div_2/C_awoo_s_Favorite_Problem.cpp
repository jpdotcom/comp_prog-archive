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
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vi a1,a2;
    FOR(n){
        if (s[i]!='b') a1.pb((int)s[i]-97);
        if (t[i]!='b') a2.pb((int)t[i]-97);
    }
    if (a1.size()!=a2.size()){
        print("NO");
        return;
    }
    FOR((int)a1.size()){
        if (a1[i]!=a2[i]){
            print("NO");
            return;
        }
    }
    stack<int> st;
    for (int i=n-1;i>=0;i--){
        if (t[i]!='b') st.push(i);
    }
    for (int i=0;i<n;i++){
        if (s[i]!='b'){
            int v=st.top();
            st.pop();
            if (s[i]=='a' && v<i){
                print("NO");
                return;
            }
            if (s[i]=='c' && v>i){
                print("NO");
                return;
            }
        }
    }
    print("YES");
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
