#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=705;
int match[maxN];
map<vector<int>,int> dp;
bool valid(int c1, int c2){
    return (c1==2 || c2==2 || (c1!=c2));
}
ll get(int i, int j, int c1, int c2){
    vector<int> vals={i,j,c1,c2};
    if (j-i+1==2) return dp[vals]=1;
    if (dp.find(vals) != dp.end()) return dp[vals];
    ll ans=0;
    if (match[i]==j){
        for (int a=0;a<3;a++)
            for (int b=0;b<3;b++){
                if (valid(c1,a) && valid(b,c2) && (match[i+1]!=j-1 || ((a!=2 && b==2) || (b!=2 && a==2)))) ans+=get(i+1,j-1,a,b);
                ans%=MOD;
            }
                
    }
    else{
        for (int a=0;a<3;a++){
            for (int b=0;b<3;b++){
                if (valid(a,b) && ((c1!=2 && a==2) || (a!=2 && c1==2)) && (match[match[i]+1]!=j || ((b!=2 && c2==2) || (c2!=2 && b==2)))) ans+=get(i,match[i],c1,a)*get(match[i]+1,j,b,c2)%MOD;
                ans%=MOD;
            }
        }
    }
    return dp[vals]=ans;
}
void solve(){
    string s; cin>>s;
    stack<int> st;
    for (int i=0;i<s.size();i++){
        if (s[i]==')'){
            int j=st.top(); st.pop();
            match[j]=i+1;
            match[i+1]=j;
        }
        else st.push(i+1);
    }
    int n=s.size();
    match[0]=n+1;
    print((get(0,n+1,2,2))%MOD);
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
    while (t--){
        solve();
    }
}
