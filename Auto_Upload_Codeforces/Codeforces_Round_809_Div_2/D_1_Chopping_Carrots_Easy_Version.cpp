#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=3005;
int s[maxN][maxN];
void solve(){

    int n,k; cin>>n>>k;
    FOR(n){
        for (int j=0;j<=3001;j++) s[i][j]=0;
    }
    FOR(n){
        int a; cin>>a;
        int v=1;
        while (v<=a+1 && v<=k){
            s[i][a/v]++;
            if (v==a+1) break;
            v=a/(a/v)+1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=3001;j++){
            s[i][j]+=s[i][j-1];
        }
    }
    int ans=1e9+7;
    if (n==1){
        print(0);
        return;
    }
    for (int i=0;i<3001;i++){
        int l=i, r=3001;
        while (l<=r){
            int a=0,b=0,c=0;
            int m=l+(r-l)/2;
            bool ok=true;
            for (int j=0;j<n;j++){
                if ((i!=0 && s[j][m]-s[j][i-1]>0) || (i==0 && s[j][m]>0)){
                    if ((s[j][m]-s[j][m-1]) && ((i!=0 && s[j][i]-s[j][i-1]) || (i==0 && s[j][i]))) c++;
                    else if ((s[j][m]-s[j][m-1])) b=1;
                    else if ((i!=0 && s[j][i]-s[j][i-1]) || (i==0 && s[j][i])) a=1;
                }
                else{
                    ok=false;
                }
            }
            if (ok){
                r=m-1;
                if (a+b+c>=2) ans=min(ans,m-i);
            }
            else l=m+1;
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
    while (t--){
        solve();
    }
}
