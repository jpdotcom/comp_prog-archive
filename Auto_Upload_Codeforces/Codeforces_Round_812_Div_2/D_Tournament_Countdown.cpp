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
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=1e6;
void solve(){
    int n; cin>>n;
    n=(1<<n);
    vi left(n);
    FOR(n) left[i]=i+1;
    while (left.size()>2){
        vi next;
        for (int i=0;i+3<left.size();i+=4){
            cout<<"? "<<left[i]<<" "<<left[i+2]<<endl;
            int out;
            cin>>out;
            if (out==0){
                next.pb(left[i+1]);
                next.pb(left[i+3]);
            }
            else if (out==1){
                next.pb(left[i]);
                next.pb(left[i+3]);
            }
            else{
                next.pb(left[i+2]);
                next.pb(left[i+1]);
            }
        }
        left=next;
    }

    if (left.size()==2){
        cout<<"? " <<left[0]<<" "<<left[1]<<endl;
        int out;
        cin>>out;
        if (out==1) left=vector<int>(1,left[0]);
        else left=vector<int>(1,left[1]);
    }
    cout<<"! " << left[0]<<endl;
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
