#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(a,b) for (int a=0;a<=b;a++)
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
#define INF (1e18)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
void solve(){
    set<string> p1,p2,p3;
    int n; cin>>n;
    string p;
    for (int i=0;i<n;i++){
        cin>>p;
        p1.insert(p);
    }
    for (int i=0;i<n;i++){
        cin>>p;
        p2.insert(p);
    }
    for (int i=0;i<n;i++){
        cin>>p;
        p3.insert(p);
    }
    int a=0,b=0,d=0;
    for (auto c: p1){
        int cnt=((int)(p2.find(c)!=p2.end()) + (int)(p3.find(c)!=p3.end()));
        if (!cnt) a+=3;
        else if (cnt==1) a++;
    }
    for (auto c: p2){
        int cnt=(int)(p1.find(c)!=p1.end()) + (int)(p3.find(c)!=p3.end());
        if (!cnt) b+=3;
        else if (cnt==1) b++;
    }
    for (auto c: p3){
        int cnt=(int)(p2.find(c)!=p2.end()) +(int)(p1.find(c)!=p1.end());
        if (!cnt) d+=3;
        else if (cnt==1) d++;
    }
    cout<<a<<' '<<b<<' '<<d<<endl;
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
