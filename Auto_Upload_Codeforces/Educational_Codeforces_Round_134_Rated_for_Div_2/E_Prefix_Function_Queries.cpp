#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
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
#define iset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=2e6;
int prefix[maxN];
int A[maxN][26];
vector<int> vals;
void get_prefix(string s){
    prefix[0]=0;

    for (int i=1;i<s.size();i++){
        int j=prefix[i-1];
        while (j>0 && s[i]!=s[j]) j=prefix[j-1];
        if (s[i]==s[j]) prefix[i]=j+1;
        else prefix[i]=0;
    }
}
void solve(){
    string s; cin>>s;
    get_prefix(s);
    FOR(26) A[0][i]=0;
    for (int i=1;i<s.size();i++){
        for (int j=0;j<26;j++){
            int prev=prefix[i-1];
            if (s[prev]-'a'==j) A[i][j]=prev+1;
            else A[i][j]=A[prev][j];
        }
    }
    int q; cin>>q;
    int on=s.size();
    FOR(q){
        string t; cin>>t;
        s+=t;
        int v=t.size();
        for (int j=on;j<s.size();j++){
            int prev=prefix[j-1];
            prefix[j]=0;
            while (prev>=on && s[prev]!=s[j]) prev=prefix[prev-1];
            if (s[prev]==s[j]) prefix[j]=prev+1;
            else if (prev<on) prefix[j]=A[prev][s[j]-'a'];
        }
        for (int j=on;j<s.size();j++){
            cout<<prefix[j]<<' ';
        }
        cout<<endl;
        for (int j=0;j<v;j++) s.pop_back();
    }
    return;
}
void precompute(){

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}

