#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
# define PI 3.14159265358979323846
# define print(x) cout<<x<<'\n'
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    long long res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=3e5;
bool dp[maxN][2];
void solve(){
    string s;
    cin>>s;
    int sn=s.length();
    if (sn<7){
        print(0);
        return;
    }

    set<string>seen;
    dp[sn-2][0]=true;
    seen.insert(s.substr(sn-2,2));
    if (sn>7){
        dp[sn-3][1]=true;
        seen.insert(s.substr(sn-3,3));
    }
    for (int i=sn-4;i>=5;i--){
        for (int j=0;j<2;j++){
            dp[i][j]=false;
            if (dp[i+j+2][j^1] || (dp[i+j+2][j] && s.substr(i,j+2) !=s.substr(i+j+2,j+2))){
                dp[i][j]=true;
                seen.insert(s.substr(i,j+2));
            }
        }
    }

    print(seen.size());
    for (auto s: seen){
        print(s);
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
