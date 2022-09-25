#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
typedef std::vector<long long> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}
int power(long long x, unsigned int y, ll p)
{
    unsigned long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void precompute(){
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vi out;
    int emp[n+m+5];
    FOR(n+m+5) emp[i]=0;
    for (int i=1;i<=n+m+1;i++){
        emp[i]+=emp[i-1];
        int days=emp[i];
        if (i==n+m+1){
            if (days==0){
                out.pb(i-1);
            }
        }
        else{
            if (days<k){
                if (days==0 && i!=1){
                    out.pb(i-1);
                    days++;
                    emp[i]++;
                    if (i+n-1<n+m+5){
                        emp[i+n-1]--;
                    }
                }
                for (int l=0;l<k-days;l++){
                    out.pb(i);
                }
                emp[i]+=k-days;
                if (i+n<n+m+5){
                    emp[i+n]=days-k;
                }
            }
        }
    }
    print(out.size());
    for (int x: out){
        cout<<x<<' ';
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }
}

