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
const int maxN=1e5+1;
void solve(){
    int n,k; cin>>n>>k;
     if (k%4==0) print("NO");
     else{
         print("YES");
         if (k&1){
             for (int i=0;i<n/2;i++){
                 cout<<i*2+1<<' '<<2*i+2<<endl;
             }
         }
         else{
             for (int i=0;i<n/2;i++){
                 if ((2*i+2)%4==0){
                     cout<<2*i+1<<' '<<2*i+2<<endl;
                 }
                 else if (k%4==2){
                     cout<<2*i+2<<' '<<2*i+1<<endl;
                 }
                 else{
                 }
             }
         }
     }
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
