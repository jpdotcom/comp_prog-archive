#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD (2012)
using namespace std;
const int maxN=1e6+1;
int prefix[maxN];
string s;
bool isPalindrome(int i, int j){
    for (int k=i,dist=0;k<i+(j-i+1)/2;k++,dist++){
        if (s[k]!=s[j-dist]) return false;
    }
    return true;
}
void solve(){
    int n; cin>>n;
    cin>>s;
    FOR(n+1) prefix[i]=0;
    FOR(n) prefix[i+1]=prefix[i]+(s[i]=='(' ? 1 :-1);
    int l=1,r=n-1,best=-1,idx=-1;
    while (l<=r){
        int m=l+(r-l)/2;
        bool ok=true;
        int stop=0,cnt=0;
        bool neg=false;
        for (int i=0;i<n;i++){
            if (cnt==m) break;
            if (prefix[i+1]-prefix[stop]<0) neg=true;
            if ((prefix[i+1]-prefix[stop]==0 && !neg) || (isPalindrome(stop,i) && i-stop+1>=2)){
                neg=false;
                stop=i+1;
                cnt++;
            }
        }
        if (ok && cnt==m){
            l=m+1;
            best=cnt;
            idx=stop;
        }
        else r=m-1;
    }
    if (idx==-1){
        cout<<0<<' '<<n<<endl;
    }
    else cout<<best<<' '<<n-idx<<endl;
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
