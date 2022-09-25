#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(n) for(int i=0;i<(int)(n);i++)
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
#define INF (1e8)
#define endl '\n'
#define MOD ((int)1e9+7)
using namespace std;
const int maxN=41;
int dp[maxN][maxN][maxN][maxN];
int pwA[maxN];
int pwB[maxN];
vector<int> trace[maxN][maxN][maxN][maxN];
void solve(){
    int l; cin>>l;
    int A,B; cin>>A>>B;
    string n; cin>>n;
    pwA[0]=pwB[0]=1;
    for (int i=1;i<=40;i++){
        pwA[i]=pwA[i-1]*10%A;
        pwB[i]=pwB[i-1]*10%B;
    }
    reverse(n.begin(),n.end());
    vector<int> start;
    trace[0][0][0][0]=vector<int>{-1,-1,-1,-1,-1};
    dp[0][0][0][0]=1;
    int curr=INF;
    for (int i=0;i<=n.size();i++){
        for (int j=0;i+j<=n.size();j++){
            for (int k=0;k<A;k++){
                for (int l=0;l<B;l++){
                    if (i+j==0) continue;
                    int idx=i+j-1;
                    dp[i][j][k][l]=0;
                    int v=n[idx]-'0';
                    if (i){
                        dp[i][j][k][l]|=(dp[i-1][j][((k-v*pwA[i-1])%A+A)%A][l]);
                        if (dp[i][j][k][l]) trace[i][j][k][l]=(vector<int>{i-1,j,((k-v*pwA[i-1])%A+A)%A,l,0});
                    }
                    if (j){
                        dp[i][j][k][l]|=(dp[i][j-1][k][((l-v*pwB[j-1])%B+B)%B]);

                        if (dp[i][j-1][k][((l-v*pwB[j-1])%B+B)%B]) trace[i][j][k][l]=vector<int>{i,j-1,k,((l-v*pwB[j-1]%B)+B)%B,1};
                    }
                    if (i+j==n.size() && !k && !l && dp[i][j][k][l] && i && j && abs(i-j)<curr){
                        start={i,j,k,l};
                        curr=abs(i-j);
                    }
                }
            }
        }
    }
    if (!start.size()) print(-1);
    else{
        start=trace[start[0]][start[1]][start[2]][start[3]];
        int sz=n.size()-1;
        vector<int> out;
        while (start[0]!=-1){
            out.pb(start[4]);
            start=trace[start[0]][start[1]][start[2]][start[3]];
        }
        for (int x: out){
            if (!x) cout<<"R";
            else cout<<"B";
        }
        cout<<endl;

    }
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
