#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define put push
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
void solve(){
    int n,m; cin>>n>>m;

    if (m==1 || (n&1)==0){
        print("YES");
        int o=1;
        int e=2;
        if (m==1){
            FOR(n) cout<<i+1<<endl;
        }
        else{
        for (int i=0;i<n/2;i++){
            for (int j=0;j<m;j++){
                cout<<o<<' ';
                o+=2;
            }
            cout<<endl;
        }
        for (int i=0;i<n/2;i++){
            for (int j=0;j<m;j++){
                cout<<e<<' ';
                e+=2;
            }
            cout<<endl;
        }
        }
    }
    else print("NO");
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


