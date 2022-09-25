#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
const int maxN=1e6+1;
int valid(string s){
    int v=0;
    for (char c:s){
        if (c=='(') v++;
        else v--;
        if (v<0) return 0;
    }
    return (v==0);
}
void solve(){
    string s;
    cin>>s;
    int sum=0;
    int qleft=0;
    FOR((int) s.size()){
        if (s[i]=='(') sum++;
        else if (s[i]==')') sum--;
        else qleft++;
    }
    sum*=-1;
    int first=-1;
    int last=1e9;
    int n=s.size();
    if (sum<0){
        for (int i=n-1;i>=0 && sum<0;i--){
            if (s[i]=='?'){
                last=i;
                s[i]=')';
                sum++;
                qleft--;
            }
        }
    }
    else if (sum>0){
        for (int i=0;i<n && sum>0;i++){
            if (s[i]=='?'){
                first=i;
                sum--;
                s[i]='(';
                qleft--;
            }
        }
    }
    for (int i=0,cnt=0;i<s.size();i++){
        if (s[i]=='?'){
            if (cnt<qleft/2){
                s[i]='(';
                first=max(first,i);
            }
            else{
                s[i]=')';
                last=min(last,i);
            }
            cnt++;
        }
    }
    string s2=s;
    if (first==-1 || last==1e9) print("YES");
    else{
        swap(s2[first],s2[last]);
        if (valid(s) && valid(s2)) print("NO");
        else print("YES");
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
