#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
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
#define INF ((ll)1e18+7)
#define MOD ((ll)1e9+7)
using namespace std;
int find_letter(int idx, vi vals){

    int l=0,r=vals.size()-1;
    int best=-1;
    while (l<=r){
        int m=l+(r-l)/2;
        int in;
        cout<<"? " << 2 << " " << vals[m]+1<< " "<<idx+1<<endl;
        cin>>in;
        if (in>vals.size()-m) r=m-1;
        else{
            l=m+1;
            best=vals[m];
        }
    }
    return best;
}
void solve(){
    int n; cin>>n;
    int occ[26];
    fill(occ,occ+26,-1);
    string s="";
    for (int i=0;i<n;i++){
        vi vals;
        for (int x: occ)
            if (x!=-1)
                vals.pb(x);
        sort(vals.begin(),vals.end());
        int v=find_letter(i,vals);
        if (v==-1){
            cout<<"? "<<1<<" "<<i+1<<endl;
            char in;
            cin>>in;
            s+=in;
            occ[in-'a']=i;
        }
        else{
            s+=s[v];
            occ[s[v]-'a']=i;
        }
    }
    cout<<"! "<<s<<endl;
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    int t=1;
    while (t--) solve();
}
