#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(1e9+7)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e5+1;
int maxF[maxN];
void solve(){
    int n,m;
    cin>>m>>n;
    vi arr[m];
    FOR(n+1)  maxF[i]=0;
    FOR(m){
        vi v(n);
        for (int j=0;j<n;j++){
            cin>>v[j];
            maxF[j]=max(maxF[j],v[j]);
        }
        arr[i]=v;
    }
    if (n-1>=m){
        int ans=1e9+7;
        FOR(n){
            ans=min(ans,maxF[i]);
        }
        print(ans);
        return;
    }
    else{
        int ans=0;
        FOR(m){
            int f1,f2,v1,v2;
            v1=v2=0,f1=0,f2=0;
            for (int j=0;j<n;j++){
                if (arr[i][j]>=v1){
                    swap(v1,v2);
                    swap(f1,f2);
                    v1=arr[i][j];
                    f1=j;
                }
                else if (arr[i][j]>=v2){
                    v2=arr[i][j];
                    f2=j;
                }
            }
            int temp=min(v1,v2);
            for (int j=0;j<n;j++){
                if (j!=f1 && j!=f2){
                    temp=min(temp,maxF[j]);
                }
            }
            ans=max(ans,temp);
        }
        print(ans);
    }

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


