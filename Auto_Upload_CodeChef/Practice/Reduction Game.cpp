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
const int maxN=55;
int arr[maxN];
void solve(){
    int n,k;
    cin>>n>>k;
    FOR(n){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    if (n==1){
        print(arr[0]);
        return;
    }
    int ans1,ans2;
    int p=0;
    ans1=ans2=0;
    FOR(n) ans1+=arr[i];
    int s=-1;
    FOR(n){
        if (arr[i]<=k){
            s++;
            ans2+=arr[i];
        }
        else break;
    }
    s++;
    if (s!=n){
        ans2+=arr[n-1];
    }
    if (s>=n-1){
        print(ans1);
        return;
    }
    int cs=0;
    for (int i=s;i<n-1;i++){
        p=modu(p+arr[i]-k,2);
        cs+=arr[i]-k;
    }
    if ((p&1)==0 && cs-(arr[n-2]-k)>=arr[n-2]-k){
        print(ans2+(n-1-s)*k);
        return;
    }
    else{
        if (p&1 && cs-(arr[n-2]-k)>=arr[n-2]-k){
            print(ans2+(n-1-s)*k-1);
        }
        else print(ans2-(2*(arr[n-2]-k)-cs)+(n-1-s)*k);
        return;
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
    cin>>t;
    while (t--){
        solve();
    }
}
