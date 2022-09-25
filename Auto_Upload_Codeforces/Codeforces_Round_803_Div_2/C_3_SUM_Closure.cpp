#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
ll a[maxN];
map<ll,int> cnt;
void solve(){
    int n; cin>>n;
    int pos=0;
    int neg=0;
    int zero=0;
    cnt.clear();
    vi vals;
    FOR(n){
        cin>>a[i];
        if (a[i]>0){
            vals.pb(a[i]);
            pos++;
            cnt[a[i]]++;
        }
        else if (a[i]<0){
            vals.pb(a[i]);
            cnt[a[i]]++;
            neg--;
        }
        else if (zero<3){
            zero++;
            cnt[a[i]]++;
            vals.pb(a[i]);
        }
    }
    if (pos>=3 || neg>=3){
        print("NO");
        return;
    }
    n=vals.size();
    sort(vals.begin(),vals.end());
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (cnt[vals[i]+vals[j]+vals[k]]==0){
                    print("NO");
                    return;
                }
            }
        }
    }
    print("YES");
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
    {solve();
    }
}
