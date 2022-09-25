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
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((int)1e9)
#define MOD ((ll)1e9+7)
using namespace std;
const int maxN=2e5+1;
string t;

void solve(){
    string s;
    cin>>s>>t;
    sort(s.begin(),s.end());
    int idx=s.size();
    bool hasc=0,hasb=0,hasa=0;
    FOR(s.size()){
       hasa|=(s[i]=='a');
       hasc|=(s[i]=='c');
       hasb|=(s[i]=='b');
    }
    if (hasa && hasb && hasc && t[1]=='b' && t[2]=='c'){
        for (int i=0,j=s.size()-1;i<=j;i++,j--){
            if (s[i]!='b'){
                j++;
            }
            else if (s[j]!='c'){
                i--;
            }
            else{
                swap(s[i],s[j]);
            }
        }
    }
    print(s);
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
    while (t--)
    {
        solve();
    }
}
