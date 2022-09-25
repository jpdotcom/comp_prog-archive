#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e5+1;
int a[maxN];
void solve(){
    priority_queue<int> q;
    ll s=0;
    int n; cin>>n;
    int ans=0;
    FOR(n){
        cin>>a[i];
        if (a[i]>=0){
            ans++;
            s+=a[i];
        }
        else if (s+a[i]>=0){
            ans++;
            s+=a[i];
            q.push(-1*a[i]);
        }
        else{
            if (q.size()>0){
                int v=-1*q.top();
                if (a[i]>v){
                    s-=v;
                    s+=a[i];
                    q.pop();
                    q.push(-1*a[i]);
                }
            }
        }
    }
    print(ans);
}
void precompute(){
}
int main(){
    precompute();
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    while (t--) solve();
}
