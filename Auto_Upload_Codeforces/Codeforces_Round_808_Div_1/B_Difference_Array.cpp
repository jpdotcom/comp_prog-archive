#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef long long ll;
typedef std::priority_queue<int> pq;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
void solve(){
    vi arr;
    int n; cin>>n;
    int c=0;
    FOR(n){
        int v; cin>>v;
        if (v) arr.pb(v);
        else c++;
    }
    if (arr.size()==0)
    {
        print(0);
        return;
    }
    FOR(n-1){
        vi next;
        if (arr.size()==0){
            print(0);
            return;
        }
        if (arr.size()==1){
            print(arr[0]);
            return;
        }
        else{
            if (c){
                next.pb(arr[0]);
                c--;
            }
            for (int i=1;i<arr.size();i++){
                if (arr[i]-arr[i-1]) next.pb(arr[i]-arr[i-1]);
                else c++;
            }
            sort(next.begin(),next.end());
            arr=next;
        }
    }
    if (arr.size()==0) print(0);
    else print(arr[0]);
    return;
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


