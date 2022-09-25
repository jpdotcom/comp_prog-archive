#include <bits/stdc++.h>
#define pb push_back
#define FOR(b) for (int i=0;i<b;i++)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define endl '\n'
#define F first 
#define S second 
# define PI 3.14159265358979323846
# define print(x) cout<<x<<'\n'
using namespace std;
ll modu(ll a,ll b){
    return (b+(a%b)) % b;
}

ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
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

const int N = 5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
const int maxN=2e5+10;
int arr[maxN];
int curr_size[maxN];
bool iscycle[maxN];
pi find_cycle(int i){
    int s1,s2;
    s1=0;
    set<int>seen;
    int prev_node=i;
    while (seen.find(i)==seen.end() && curr_size[i]==0){
        seen.insert(i);
        s1++;
        curr_size[i]=s1;
        prev_node=i;
        i=arr[i];
    }
    if (seen.find(i)==seen.end()){
        return make_pair(curr_size[prev_node],-1);
    }
    else{
        while (i!=prev_node){
            iscycle[i]=true;
            i=arr[i];
        }
        iscycle[i]=true;
        i=arr[i];
    }
    return make_pair(curr_size[i]-1,curr_size[prev_node]-curr_size[i]+1);
}
void solve(){
    cin>>n;
    FOR(n){
        int val;
        cin>>val;
        arr[i+1]=val;
        curr_size[i+1]=0;
    }
    ll ans=1;
    for (int i=1;i<=n;i++){
        if (curr_size[i]==0){
           pi p = find_cycle(i);
           ll v1=power(2,p.F,1e9+7),v2=((p.S==-1) ? 1 : power(2,p.S,1e9+7)-2);
           ans*=modu(v1*v2,1e9+7);
           ans=modu(ans,1e9+7);
        }
    }
    print(ans);

}
void precompute(){
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
    }


}
