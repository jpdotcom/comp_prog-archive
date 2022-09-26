#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
void solve(){
    string s;
    cin>>s;
    int ans=0;
    set<int>l;
    FOR((int) s.size()){
        l.insert(s[i]);
        if (l.size()>3){
            l.clear();
            ans++;
            i--;
        }
    }
    ans+=(l.size()>0);
    print(ans);
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
