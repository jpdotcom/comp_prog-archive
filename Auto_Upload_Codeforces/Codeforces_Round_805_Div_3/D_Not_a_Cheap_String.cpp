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
    unordered_map<int,int> l;
    string s; cin>>s;
    int p; cin>>p;
    string t=s;
    sort(t.begin(),t.end());
    int v=0;
    FOR((int) s.size()) v+=(s[i]-'a'+1);
    for (int i=(int)t.size()-1;i>=0 && v>p;i--){
        v-=(t[i]-'a'+1);
        l[t[i]]++;
    }
    FOR((int) s.size()){
        if (l[s[i]]>0) l[s[i]]--;
        else cout<<s[i];
    }
    cout<<endl;

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
