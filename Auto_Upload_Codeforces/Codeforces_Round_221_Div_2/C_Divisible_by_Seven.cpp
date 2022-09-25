#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
#define mp(a,b) make_pair(a,b)
typedef long long ll;
typedef std::priority_queue<pi> pq;
#define endl '\n'
#define F first 
#define S second 
# define PI 3.14159265358979323846
# define print(x) cout<<x<<'\n'
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
ll power(ll x, ll y, ll p)
{
    long long res = 1;     
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res=modu(res*x,p);
        y = y>>1; 
        x = modu((x*x),p);
    }
    return res;
}
int m[7];
int get_num(int arr[]){
    int ans=0;
    FOR(4){
        ans*=10;
        ans+=arr[i];
    }
    return ans;
}
void solve(){
    string n;
    cin>>n;
    int ans=0;
    vi a;
    bool seen[10];
    int arr[4]={1,6,8,9};
    int val=get_num(arr);
    m[val%7]=val;
    while (next_permutation(arr,arr+4)){
        val=get_num(arr);
        m[val%7]=val;
    }
    FOR(10) seen[i]=false;
    FOR((int)n.size()){
        int val=n[i]-'0';
        if ((val==1 || val==6 || val==8 || val==9) && (!seen[val])){
            seen[val]=true;
        }
        else{
            a.pb(val);
            ans=modu(modu(3*ans,7)+modu(val,7),7);
        }
    }
    if (ans==0){
        ans=7;
    }
    ll p=power(10,n.size()-4,7);
    int need=0;
    for (int i=0;i<7;i++){
        if (modu((p*i),7)==7-ans) need=i;
    }
    string num=to_string(m[need]);
    cout<<num;
    for (int x:a){
        cout<<x;
    }
}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}
