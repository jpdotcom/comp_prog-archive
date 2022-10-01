#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e6+1;
int a[maxN];
map<int,int> cnt;
void solve(){
    int n; cin>>n;
    cnt.clear();
    FOR(n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int c=0;
    int g=0;
    int v=0;
    int mx=0;
    int val=0;
    for (int i=0;i<n;i++){
        if (cnt[a[i]]==1){
            c++;
            v=a[i];
        }
        else{
            mx=max(mx,cnt[a[i]]);
            val=max(val,a[i]);
        }
    }
    if (c==1 && mx==2 && v>val) print(2);
    else print((c+1)/2);

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
    while (t--){
        solve();
    }
}



