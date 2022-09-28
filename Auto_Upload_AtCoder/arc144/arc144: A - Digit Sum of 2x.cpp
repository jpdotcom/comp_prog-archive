#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
#define bit(x,y) ((x>>y)&1)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
const int maxN=1e6+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    print(2*n);
    string ans="";
    int l=0,r=n;
    while (l<=r){
        int m=l+(r-l)/2;
        int dig=0;
        string b;
        for (int i=0;i<m;i++){
            int v=max(0,min(4,n-(dig+4*(m-i-1))));
            dig+=v;
            b+=('0'+v);
        }
        if (dig==n){
            ans=b;
            r=m-1;
        }
        else l=m+1;
    }
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
