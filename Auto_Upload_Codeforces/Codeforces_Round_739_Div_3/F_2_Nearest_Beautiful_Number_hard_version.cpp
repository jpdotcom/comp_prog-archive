#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1e6+2;
vector<vector<int>>digits;
vector<vector<int>> best(1024,vector<int>(10));
vector<ll> p10(11);
void solve(){
    string n; cin>>n;
    int k; cin>>k;
    ll out=INF;
    for (int i=1;i<1024;i++){
        if (__builtin_popcount(i)<=k){
            vector<int> &dig=digits[i];
            int s=dig[0];
            bool ok=true;
            ll ans=0;
            for (int j=0;j<n.size();j++){
                int num=best[i][n[j]-'0'];
                if (num==dig.size()){
                    ok=false;
                    break;
                }
                if (dig[num]>n[j]-'0'){
                    ans*=10;
                    ans+=dig[num];
                    ans*=p10[n.size()-j-1];
                    ans+=(p10[n.size()-j-1]-1)/9*s;
                    break;
                }
                else{
                    if (num!=dig.size()-1){
                        ll temp=10*ans+dig[num+1];
                        //if (i==10 && j==2) print(temp);
                        temp*=p10[n.size()-j-1];
                        temp+=(p10[n.size()-j-1]-1)/9*s;
                        //if (i==10 && j==2) print(dig[num+1]);
                        out=min(out,temp);
                    }
                    ans*=10;
                    ans+=dig[num];
                }
            }
            if (ok) out=min(out,ans);
        }
    }
    print(out);
}
void precompute(){
    digits.pb(vector<int>(0));
    FOR(1024){
        if (i!=0){
            vector<int> push;
            for (int j=0;j<=9;j++){
                if (bit(i,j)) push.pb(j);
            }
            for (int k=0;k<=9;k++){
                int idx=lower_bound(all(push),k)-push.begin();
                best[i][k]=idx;
            }
            digits.pb(push);
        }
    }
    p10[0]=1;
    for (int i=1;i<=10;i++) p10[i]=p10[i-1]*10;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
        
    }
}
