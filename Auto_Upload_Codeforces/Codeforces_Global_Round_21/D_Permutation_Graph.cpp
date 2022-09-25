#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e9+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=3e5+1;
int t[2*maxN][2];
int n;
int a[maxN];
void update(int i, int val){
    for (i+=n,t[i][0]=t[i][1]=val,i>>=1;i>=1;i>>=1){
        t[i][0]=min(t[i<<1][0],t[(i<<1)|1][0]);
        t[i][1]=max(t[i<<1][1],t[(i<<1)|1][1]);
    }
}
int get(int a, int b, int i){
    int ans=(i==0 ? INF :-1*INF);
    for (a+=n,b+=n;a<=b;a>>=1,b>>=1){
        if (a&1){
            if (i) ans=max(ans,t[a++][i]);
            else ans=min(ans,t[a++][i]);
        }
        if ((b&1)==0){
            if (i) ans=max(ans,t[b--][i]);
            else ans=min(ans,t[b--][i]);
        }

    }
    return ans;
}
void solve(){
    cin>>n;
    FOR(n){
        cin>>a[i];
        update(i,a[i]);
    }
    int ans=0;
    for (int i=0;i<n-1;){
        int idx1=-1,idx2=-1;
        int l=i+1,r=n-1,b=i+1;
        while (l<=r){
            int m=l+(r-l)/2;
            if (get(i+1,m,1)>a[i]) r=m-1;
            else{
                b=m;
                l=m+1;
            }
        }
        l=i,r=b;
        int mi=get(i,b,0);
        while (l<=r){
            int m=l+(r-l)/2;
            if (get(i,m,0)>mi) l=m+1;
            else{
                idx1=m;
                r=m-1;
            }
        }
        l=i+1,r=n-1,b=i+1;
        while (l<=r){
            int m=l+(r-l)/2;
            if (get(i+1,m,0)<a[i]) r=m-1;
            else{
                b=m;
                l=m+1;
            }
        }
        l=i,r=b;
        int mx=get(i,b,1);
        while (l<=r){
            int m=l+(r-l)/2;
            if (get(i,m,1)<mx) l=m+1;
            else{
                idx2=m;
                r=m-1;
            }
        }
        i=max(idx1,idx2);
        ans++;
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
