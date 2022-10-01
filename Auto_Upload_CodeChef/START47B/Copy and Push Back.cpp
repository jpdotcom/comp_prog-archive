#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=4e6+1;
int seen[26];
int get_ans(string s, int i){
    if (i==-1) return true;
    if ((i+1) & 1){
        return get_ans(s,i-1);
    }
    else{
        for (int j=0;j<(i+1)/2;j++){
            if (s[j]!=s[(i+1)/2+j]) return false;
        }
        return get_ans(s,(i+1)/2-1);
    }
}
void solve(){
    int n; cin>>n;
    string s;
    cin>>s;
    print(((get_ans(s,n-1)) ? "YES" : "NO"));
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


