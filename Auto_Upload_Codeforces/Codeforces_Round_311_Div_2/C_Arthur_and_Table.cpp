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
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=1e5+5;
int sum[maxN];
int cnt[maxN];
bool seen[maxN];
vector<pi> arr;
void solve(){
    int n;
    cin>>n;
    int max_val=-1;
    FOR(maxN){
        sum[i]=cnt[i]=0;
        seen[i]=false;
    }
    FOR(n){
        int val;
        pi p;
        cin>>val;
        max_val=max(max_val,val);
        p.F=val;
        arr.pb(p);
        cnt[val]++;
    }
    FOR(n){
        int val;
        cin>>val;
        arr[i].S=val;
        sum[arr[i].F]+=val;
    }
    
    for (int i=1;i<maxN;i++){
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];
    }
    sort(arr.begin(),arr.end());
    int cost[205];
    FOR(205) cost[i]=0;
    int ans=1e9;
    for (pi p:arr){
        int a=p.F,b=p.S;
        int ca=0;
        if (!seen[a]){
            seen[a]=true;
            int c=n-(cnt[max_val]-cnt[a]);
            ca+=sum[max_val]-sum[a];
            c=max(c-2*(cnt[a]-cnt[a-1])+1,0);
            for (int i=0;i<205;i++){
                if (c==0) break;
                if (c-cost[i]>=0){
                    ca+=i*cost[i];
                    c-=cost[i];
                }
                else{
                    ca+=c*i;
                    c=0;
                }
            }
            ans=min(ans,ca);
        }
        cost[b]++;
    }
    print(ans);
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
