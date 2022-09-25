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
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=1005;
int dp[1005][3];
string s;
int query(int i,int j,int l){
    int si=i/l,sj=j/l;
    int a,b,c;
    a=b=c=0;
    if (si==sj){
        for (int k=i;k<=j;k++){
            if (s[k]=='('){
                    b++;
            }
            else{
                if (b<=0){
                    c++;
                }

                else{
                    b--;
                    a++;
                }
            }
        }
        return a;
    }
    
    for (int k=i;k<=(si+1)*l-1;k++){
        if (s[k]=='('){
            b++;
        }
        else{
            if (b<=0){
                c++;
            }
            else{
                b--;
                a++;
            }
        }

    }
    for (int k=si+1;k<sj;k++){
        int a2=dp[k][0],b2=dp[k][1],c2=dp[k][2];
        int t=min(b,c2);
        a+=(a2+t);
        b+=(b2-t);
        c+=(c2-t);
    }
    for (int k=sj*l;k<=j;k++){
        if (s[k]=='('){
            b++;
        }
        else{
            if (b<=0){
                c++;
            }
            else{
                b--;
                a++;
            }
        }
    }
    return a;
}
void solve(){
    int n,m;
    cin>>s;
    cin>>m;
    n=s.length();
    int ci=0;
    int next_val=(int)sqrt(n);
    int a=0,b=0,c=0;
    FOR(n){
        if (i==next_val){
            dp[ci][0]=a,dp[ci][1]=b,dp[ci][2]=c;
            ci+=1;
            next_val+=(int)sqrt(n);
            a=b=c=0;
        }
        if (s[i]=='('){
            b++;
        }
        else{
            if (b<=0){
                c++;
            }
            else{
                b--;
                a++;
            }
        }
    }
    dp[ci][0]=a,dp[ci][1]=b,dp[ci][2]=c;
    FOR(m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        print(2*query(a,b,(int)(sqrt(n))));
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
