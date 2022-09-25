#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=3e5+1;
int a[maxN];
int n; 
int table[30*maxN][2][2];
const int mxSize=2;
const char baseChar='0';
struct Vertex{
    int next[mxSize];
    int cnt=0;
    Vertex(){
        fill(begin(next),end(next),-1);
    }
};
struct Trie{
    vector<Vertex> t;
    Trie(){
        Vertex root;
        t.push_back(root);
    }
void insert(string s, int j,int val,int aval){
    int v=0;
    for (int i=0;i<s.size();i++){
        int b1=bit(j,s.size()-1-i);
        int b2=bit(aval,s.size()-1-i);
        table[v][b2][b1]=max(table[v][b2][b1],val);
        int idx=s[i]-baseChar;
        if (t[v].next[idx]==-1){
            t[v].next[idx]=t.size();
            Vertex u;
            t.push_back(u);
        }
        v=t[v].next[idx];
    }
    t[v].cnt++;
}
void remove(string s){

    int v=0;
    for (int i=0;i<s.size();i++){
        int idx=s[i]-baseChar;
        if (t[v].next[idx]==-1) return;
        v=t[v].next[idx];
    }
    t[v].cnt--;
}
};
void solve(){
    cin>>n;
    FOR(n) cin>>a[i];
    int ans=0;
    FOR(30*n+10){
        table[i][0][0]=table[i][0][1]=table[i][1][0]=table[i][1][1]=0;
    }

    Trie ti;
    for (int i=0;i<n;i++){
        int val=1;
        int v=0;
        string s=bitset<30>(a[i]^i).to_string();
        for (int j=0;j<30;j++){
            int b1=bit(a[i],29-j);
            int b2=bit(i,29-j);
            val=max(val,1+table[v][b2][b1^1]);
            v=ti.t[v].next[s[j]-'0'];
            if (v==-1) break;
        }
        ti.insert(s,i,val,a[i]);
        ans=max(ans,val);
    }
    print(ans);
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
    cin>>t;
    while (t--)
    {
        solve();
    }
}
