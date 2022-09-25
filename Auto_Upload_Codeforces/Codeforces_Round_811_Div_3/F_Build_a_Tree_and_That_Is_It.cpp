#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
void solve(){
    int n,a,b,c;
    vector<vector<int>> edges(3,vector<int>(3));
    cin>>n>>a>>b>>c;
    edges[0][0]=a;
    edges[0][1]=1;
    edges[0][2]=2;
    edges[1][0]=b;
    edges[1][1]=2;
    edges[1][2]=3;
    edges[2][0]=c;
    edges[2][1]=1;
    edges[2][2]=3;
    sort(edges.begin(),edges.end());
    int root=edges[0][1];
    if (edges[0][1]==edges[1][1] || edges[0][1]==edges[1][2]){
        root=edges[0][2];
    }
    
    if (edges[0][0]>n-1){
        print("NO");
        return;
    }
    vector<bool>used(n+1);
    vector<pi> out;
    int left=n-1;
    int curr=root;
    used[root]=true;
    vi back;
    back.pb(root);
    if (edges[0][0]!=1){
        curr=4;
        out.pb(mp(root,4));
        back.pb(4);
        left--;
        used[4]=true;
    for (int i=5,k=0;i<=n && k<edges[0][0]-2;i++){
        if (!used[i]){
            used[i]=true;
        left--;
        out.pb(mp(curr,i));
        back.pb(i);
        curr=i;
        k++;
        }
    }
  
    if (left<0){
        print("NO");
        return;
    }
    }
    out.pb(mp(curr,(root==edges[0][1] ? edges[0][2] : edges[0][1])));
    used[(root==edges[0][1] ? edges[0][2] : edges[0][1])]=true;
    left--;
    back.pb((root==edges[0][1] ? edges[0][2] : edges[0][1]));
    bool ok=false;
    int other=6-edges[0][1]-edges[0][2];
    b=(edges[1][1]==root || edges[1][2]== root ? edges[2][0] : edges[1][0]);
    c=(edges[1][1]==root || edges[1][2]== root ? edges[1][0] : edges[2][0]);
    for (int i=back.size()-1,dist=0;i>=0;i--,dist++){
        int second_dist=i;
        if (b-dist==c-second_dist && c-second_dist<=left && c-second_dist>0){
            ok=true;
            int start=back[i];
            int end=b-dist-1;
            used[start]=true;
            for (int j=1;end>0;j++,end){
                if (!used[j] && j!=other){
                    out.pb(mp(start,j));
                    used[j]=true;
                    start=j;
                    end--;
                }
            }
            out.pb(mp(start,other));
            used[start]=true;
            used[other]=true;
            start=other;
            for (int j=1;j<=n;j++){
                if (!used[j]){
                    out.pb(mp(start,j));
                    used[j]=true;
                    start=j;
                }
            }
            break;
        }
    }
    if (!ok){
        print("NO");
        return;
    }
    print("YES");
    for (pi p : out){
        cout<<p.F<<' '<<p.S<<endl;
    }
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
