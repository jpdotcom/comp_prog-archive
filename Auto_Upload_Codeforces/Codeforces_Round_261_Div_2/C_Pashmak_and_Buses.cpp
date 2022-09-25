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
bool g(int a,int b,int c){
    int ans=1;
    while (b--){
        ans*=a;
        if (ans>=c) return true;
    }
    return (ans>=c);
}
const int maxval=1005;
int arr[maxval][maxval];
int perm[maxval];
bool nextperm(int i,int m){
    if (i==0 && perm[i]==m){
        return false;
    }
    else{
        if (perm[i]!=m){
            perm[i]++;
            return true;
        }
        else{
            perm[i]=1;
            return nextperm(i-1,m);
        }
    }
}
void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    if (!g(k,d,n)){
        print(-1);
        return;
    }
    FOR(d){
        perm[i]=1;
    }
    FOR(d){
        arr[i][0]=perm[i];
    }
    int s=1;
    while (s<n && nextperm(d-1,min(k,n))){
        FOR(d){
            arr[i][s]=perm[i];
        }
        s++;
    }
    FOR(d){
        for (int j=0;j<n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
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
