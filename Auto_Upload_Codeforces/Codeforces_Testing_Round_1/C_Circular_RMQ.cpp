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
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
const int maxN=200050;
ll tree[4*maxN];
ll lazy[4*maxN];
ll INF=1e9;
void prop(int k){

    tree[k]+=lazy[k];
    ll val=lazy[k];
    lazy[k]=0;
    if (2*k>=4*maxN) return;
    lazy[2*k]+=val,lazy[2*k+1]+=val;
    return;
}
ll query(int a,int b,int k,int x,int y){
    if (b<x || a>y || x>y) return INF;
    if (a<=x && y<=b) return tree[k]+lazy[k];
    prop(k);
    int d=(x+y)/2;
    return min(query(a,b,2*k,x,d),query(a,b,2*k+1,d+1,y));
}
ll update(int a,int b,int k,int x,int y,ll val){
    if (b<x || a>y || x>y) return INF;
    if (a<=x && y<=b){
        lazy[k]+=val;
        return tree[k]+lazy[k];
    }
    //prop(k);
    int d=(x+y)/2;
    update(a,b,2*k,x,d,val),update(a,b,2*k+1,d+1,y,val);
    tree[k]=min(tree[2*k]+lazy[2*k],tree[2*k+1]+lazy[2*k+1]);
    return tree[k];
}
void build(){
    FOR(4*maxN){
        lazy[i]=tree[i]=0;
    }
}
void solve(){
    int n;
    cin>>n;
    build();
    FOR(n){
        ll val;
        cin>>val;
        update(i,i,1,0,n-1,val);
    }
    int q;
    cin>>q;
    string s;
    getline(cin,s);
    FOR(q){
        string line;
        getline(std::cin, line);
        istringstream iss(line);
        vi numbers;
        ll enterNumber;
        while (iss >> enterNumber)
        {
            numbers.push_back(enterNumber);
        }
        if (numbers.size()==3){
            if (numbers[0]>numbers[1]){
                update(numbers[0],n-1,1,0,n-1,numbers[2]);
                update(0,numbers[1],1,0,n-1,numbers[2]);
            }
            else{
                update(numbers[0],numbers[1],1,0,n-1,numbers[2]);
            }
        }
        else{
            if (numbers[0]>numbers[1]){
                print(min(query(numbers[0],n-1,1,0,n-1),query(0,numbers[1],1,0,n-1)));
            }
            else{
                print(query(numbers[0],numbers[1],1,0,n-1));
            }
        }
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
