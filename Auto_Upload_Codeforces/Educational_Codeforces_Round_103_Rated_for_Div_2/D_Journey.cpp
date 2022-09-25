#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD (2012)
using namespace std;
const int maxN=1e6+1;
int longest[maxN][2];
void solve(){
     int n; cin>>n;
     string s; cin>>s;
     longest[0][1]=0;
     longest[n][0]=0;
     for (int i=1;i<=n;i++){
         longest[i][1]=0;
         if (s[i-1]=='L'){
             longest[i][1]=1+(i-2>=0 && s[i-2]=='R' ? 1+longest[i-2][1] : 0);
         }
     }
     for (int i=n-1;~i;i--){
         longest[i][0]=0;
         if (s[i]=='R'){
             longest[i][0]=1+(i<n-1 && s[i+1]=='L' ? 1+longest[i+2][0] :0); 
         }
     }
     FOR(n+1){
         cout<<longest[i][0]+longest[i][1]+1<<' ';
     }
     cout<<endl;
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
    while (t--){
        solve();
    }
}
