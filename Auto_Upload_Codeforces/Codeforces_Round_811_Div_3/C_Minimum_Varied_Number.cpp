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
bool used[40];
int gettot(int v, int start){
    int end=9;
    int s=0;
    while (end!=start-1 && v>0){
        s+=end;
        end--;
        v--;
    }
    return s;
}
void solve(){

    int n; cin>>n;
    FOR(40) used[i]=false;
    int min_req=0;
    int v=9;
    int t=0;
    while (t<n){
        t+=v;
        min_req++;
        v--;
    }
    int ans=0;
    int curr=0;
    FOR(min_req){
        ans*=10;
        for (int j=0;j<10;j++){
            if (!used[j] && gettot((min_req-i-1),j+1)>=n-curr-j){
                ans+=j;
                curr+=j;
                used[j]=true;
                break;
            }
        }
    }
    print(ans);
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
