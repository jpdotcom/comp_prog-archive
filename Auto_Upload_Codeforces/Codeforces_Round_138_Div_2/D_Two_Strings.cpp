#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
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
const int maxN=300005;
map<char,vi> mp;
int pl[maxN];
int pr[maxN];
bool valid[maxN];
int search(char idx,int side,int add){
    int l=0,r=mp[idx].size()-1;
    int best=-1;
    while (l<=r){
        int m=l+(r-l)/2;
        int sign=1;
        if (side==1){
            sign=-1;
        }
        if (valid[add+sign*mp[idx][m]]){
            best=mp[idx][m];
            if (side==0){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        else{
            if (side==0){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

    }
    return best;
}
void solve()
{
    string s;
    string t;
    cin>>s>>t;
    int sn=s.length(),tn=t.length();
    pl[0]=(s[0]==t[0] ? 0:-1);
    valid[0]=true;
    if (pl[0]!=-1){
        valid[1]=true;
    }
    int k=0;
    for (char c:t){
        if (mp.find(c)==mp.end()){
            vi p;
            mp[c]=p;
        }
        mp[c].pb(k);
        k++;
    }
    for (int i=1;i<sn;i++){
        pl[i]=search(s[i],0,0);
        if (pl[i]!=-1){
            valid[pl[i]+1]=true;
        }
    }
    FOR(maxN){
        valid[i]=false;
    }
    pr[sn-1]=(s[sn-1]==t[tn-1] ? tn-1 : tn);
    valid[0]=true;
    if (pr[sn-1]!=tn){
        valid[1]=true;
    }
    for (int i=sn-2;i>-1;i--){
        pr[i]=search(s[i],1,tn-1);
        if (pr[i]!=-1){
            valid[tn-pr[i]]=true;
        }
        else{
            pr[i]=tn;
        }
    }
    for (int i=0;i<sn;i++){
        if (pl[i]<pr[i]){
            print("No");
            return;
        }
    }
    print("Yes");
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
