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
#define INF ((int)1e9+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=1e6+1;
int dp[maxN][3];
int prefix[maxN];
pair<int,int> trace[maxN][3];
map<int,pair<int,int>> smallest;
void solve(){
    string s; cin>>s;
    int n=s.size();
    prefix[0]=0;
    FOR(s.size()){
        prefix[i+1]=(prefix[i]+(s[i]-'0'))%3;
    }
    dp[0][1]=INF;
    dp[0][2]=INF;
    dp[0][0]=0;
    trace[0][0]=mp(-1,-1);
    for (int i=1;i<=s.size();i++){
        for (int j=0;j<3;j++){
            dp[i][j]=INF;
            int need=((j-(s[i-1]-'0'))%3+3)%3;
            if (need==0 && s[i-1]!='0'){
                dp[i][j]=i-1;
                trace[i][j]=mp(0,0);
            }
            if (smallest.find(need)!=smallest.end()){
                if (dp[i][j]>smallest[need].S+i-1){
                    dp[i][j]=smallest[need].S+i-1;
                    trace[i][j]=mp(smallest[need].F,need);
                }
            }
        }
        for (int j=0;j<3;j++){
            int add=j;
            if (smallest.find(add) == smallest.end() || dp[i][j]-i<smallest[add].S){
                smallest[add]=mp(i,dp[i][j]-i);
            }
        }
    }
    int mi=INF;
    int idx=-1;
    FOR(n){
        if (mi>dp[i+1][0]+(n-(i+1))){
            idx=i+1;
            mi=dp[i+1][0]+(n-(i+1));
        }
    }
    if (idx!=-1){
        string out="";
        pi curr=mp(idx,0);
        while (curr.F!=0){
            out+=s[curr.F-1];
            curr=trace[curr.F][curr.S];
        }
        reverse(out.begin(),out.end());
        print(out);
    }
    else{
        int haszero=0;
        for (auto c: s) haszero+=(c-'0' == 0);
        if (haszero) print('0');
        else print(-1);
    }
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
        
    }
}
