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
const int maxN=3e5+10;
int n;
int a[maxN];
int b[maxN];
pi p1,p2;
int valid(int i, int j){
    return (i>0 && i<=8  && j>0 && j<=8);
}
int get(int i, int j, int k, int l){

    return (i==k || j==l || abs(j-l)==abs(i-k));
}
int find(int x,int y){
    vector<int> xv;
    vector<int> yv;
    for (int i=-1;i<=1;i++){
        for (int j=-1;j<=1;j++){
        if (i==0 && j==0) continue;
        if (valid(x+i,y+j)){
            xv.pb(x+i);
            yv.pb(y+j);
        }
        }
    }
    for (int i=1;i<=8;i++){
        for (int j=1;j<=8;j++){
            for (int k=1;k<=8;k++){
                for (int l=1;l<=8;l++){
                    if (get(i,j,x,y)) continue;
                    vector<int> good(xv.size(),0);
                    int all=0;
                    for (int m=0;m<xv.size();m++){
                        if (get(i,j,xv[m],yv[m])) good[m]=true;
                        all+=good[m];
                    }
                    if (all==xv.size()){
                        p1=mp(i,j);
                        return 1;
                    }
                    if (get(k,l,x,y)) continue;
                    bool ok=true;
                    for (int m=0;m<xv.size();m++){
                        if (get(k,l,xv[m],yv[m])) good[m]=true;
                        ok&=good[m];
                    }
                    if (ok){
                        p1=mp(i,j);
                        p2=mp(k,l);
                    }

                }
            }
        }
    }
    return 2;

}
void solve(){
    int x,y; cin>>x>>y;
    p1=p2=mp(-1,-1);
    int v=find(x,y);
    vector<vector<int>> board(8,vector<int>(8,0));
    board[x-1][y-1]=1;
    board[p1.F-1][p1.S-1]=2;
    if (v==2) board[p2.F-1][p2.S-1]=2;
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
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
    cin>>t;
    while (t--)
    {
        solve();
    }
}
