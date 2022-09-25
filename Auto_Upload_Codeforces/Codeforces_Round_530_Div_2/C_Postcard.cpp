#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)998244353)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=205;
bool isLetter(char c){
    return c!='*' && c!='?';
}
void solve(){
    string s; cin>>s;
    int n=s.size();
    int k; cin>>k;
    int m=0;
    int q=0;
    int star=0;
    FOR(n-1){
        m+=(isLetter(s[i]) && isLetter(s[i+1]));
    }
    if (s[n-1]!='?' && s[n-1]!='*') m++;
    FOR(n){
        q+=(s[i]=='*');
        star+=(s[i]=='?');
    }
    if (q==0 && star==0){
        if (s.size()==k) print(s);
        else print("Impossible");
    }
    else if (m+q+star<k){
        if (q==0){
            print("Impossible");
            return;
        }
        int idx=0;
        FOR(n)
            if (s[i]=='*')
                idx=i;
        FOR(idx){
            if (isLetter(s[i])) cout<<s[i];
        }
        FOR(k-m-q-star) cout<<s[idx-1];
        for (int i=idx;i<n;i++) 
            if (isLetter(s[i]))
                cout<<s[i];
    }
    else{
        int left=m+q+star-k;
        if (left>q+star){
            print("Impossible");
            return;
        }
        for (int i=0;i<n;i++){
            if (isLetter(s[i]) && (i==n-1 || left==0)) cout<<s[i];
            else if (isLetter(s[i]) && left>0 && (i!=n-1 && !isLetter(s[i+1]))) left--;
            else if (isLetter(s[i])) cout<<s[i];
        }
    }
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
        
    }
}
