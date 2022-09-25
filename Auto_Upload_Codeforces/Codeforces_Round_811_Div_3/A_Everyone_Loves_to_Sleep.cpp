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
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=1e6+1;
pi times[maxN];
void solve(){
    int n,H,M; cin>>n>>H>>M;
    FOR(n){
        cin>>times[i].F>>times[i].S;
    }
    sort(times,times+n);
    times[n]=mp(times[0].F+24,times[0].S);
    int h=0;
    int t=0;
    for (int i=0;i<n+1;i++){
        if (times[i]>=mp(H,M)){
            if (times[i].F>H){
                h=times[i].F-H;
                if (times[i].S<M){
                    h--;
                    times[i].S+=60;
                    t=times[i].S-M;
                }
                else{
                    t=times[i].S-M;
                }
            }
        else{
            h=0;
            t=times[i].S-M;
        }
        break;
        }
    }
    cout<<h<<' '<<t<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}
