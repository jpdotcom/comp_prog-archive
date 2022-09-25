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
const int maxN=2e5+10;
set<int> c1={1,2,4,7,9,8,6,3};
set<int> c2={5,0};
set<int> addOne={7,9,3,6};
int a[maxN];
void solve(){
    int n; cin>>n;
    int v1=0;
    int v2=0;
    int parity=-1;
    bool ok=true;
    FOR(n){
        int v; cin>>v;
        a[i]=v;
        v1+=(c1.find(v%10)!=c1.end());
        v2+=(c2.find(v%10)!=c2.end());
        if (c1.find(v%10)!=c1.end()){
            int add=(addOne.find(v%10) != addOne.end());
            if (parity==-1){
                parity=((v/10+add)&1);
            }
            else if (((v/10+add)&1)!=parity){
                ok=false;
            }
        }
    }
    if (v1>0 && v2>0){
        print("NO");
        return;
    }
    if (v1>0){
        if (ok) print("YES");
        else print("NO");
    }
    if (v2>0){
        sort(a,a+n);
        if (a[0]==a[n-1] || (a[n-1]-a[0]==5 && a[n-1]%10==0)) print("YES");
        else print("NO");
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
