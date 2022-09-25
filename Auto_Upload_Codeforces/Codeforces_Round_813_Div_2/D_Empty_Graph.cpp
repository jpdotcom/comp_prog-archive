#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
const int INF=1e9+7;
int a[maxN];
int n,k;
bool can(int val){
    vector<int> arr(n,0);
    FOR(n) arr[i]=a[i];
    int t=0;
    FOR(n){
        if (2*arr[i]<val){
            arr[i]=1e9;
            t++;
        }
    }
    FOR(n-1){
        int v=t+(arr[i]<val)+(arr[i+1]<val);
        if (v<=k) return true;
    }
    return false;
}
void solve(){
    cin>>n>>k;
    FOR(n) cin>>a[i];
    int low=0,high=1e9,ans=0;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (can(mid)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    print(ans);
}

void precompute(){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--) solve();
}
