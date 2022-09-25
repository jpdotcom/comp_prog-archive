#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+100;

int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i=2;i*i<=n;i++)
    {
        while(n%(i*i)==0)
            n/=i;
    }
    cout<<n<<endl;
    return 0;
