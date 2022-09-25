#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<long long> vi;
typedef std::pair<long long,long long> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<int> pq;
#define endl '\n'
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define MOD (ll)(998244353)
#define iset tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define bit(x,s) ((x>>s)&1)
using namespace std;
using namespace __gnu_pbds;
const int maxN=1005;
int ne[maxN][maxN];
int a[maxN][maxN];
int get_row(int r, int c){
    if (ne[r][c]==r) return ne[r][c];
    return ne[r][c]=get_row(ne[r][c],c);
}
void un(int r1, int r2, int c){
    r1=get_row(r1,c);
    r2=get_row(r2,c);
    if (r1!=r2){
        if (r2>r1) ne[r1][c]=ne[r2][c];
        else ne[r2][c]=ne[r1][c];
    }
    return;
}
void solve(){
    int n,m,k; cin>>n>>m>>k;
    FOR(n+1){
        for (int j=0;j<m+1;j++) ne[i][j]=i;
    }
    FOR(n)
        for (int j=0;j<m;j++) {
            cin>>a[i][j];
            if (a[i][j]==2){
                un(i,i+1,j);
            }
        }
    FOR(k){
        int col; cin>>col; col--;
        int r=0,c=col;
        while (r!=n){
            if (a[r][c]==2){
                un(r,r+1,c);
                r=get_row(r,c);
            }
            else{
                if (a[r][c]==1){
                    a[r][c]=2;
                    c++;
                }
                else{
                    a[r][c]=2;
                    c--;
                }
            }
        }
        cout<<c+1<<' ';
    }
    cout<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
