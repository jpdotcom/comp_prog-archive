#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long long> vi;
typedef long long ll;
typedef std::pair<int,int> pi;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define endl '\n'
#define print(x) cout<<x<<'\n'
#define bit(x,s) ((x>>s)&1)
#define oset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+10)
#define all(a) (a).begin(), (a).end()
#define MOD ((ll)1e9+7)
using namespace std;
using namespace __gnu_pbds;
using u64 = uint64_t;
using u128 = __uint128_t;
const int maxN=2e5+1;
int a[maxN];
void solve(){
    int n; cin>>n;
    int cnt1=0;
    int cntr=0;
    int vr=0;
    FOR(n){
        cin>>a[i];
        cnt1+=(a[i]==1);
        cntr+=(a[i]>1 ? a[i] : 0);
        vr+=(a[i]>1);
    }
    if (cntr-2*(vr-1)<cnt1){
        print("NO");
        return;
    }
    else if (n==1){
        cout<<"YES"<<' '<<1<<endl;
        return;
    }
    else{
        for (int i=0;i<n && cnt1<2;i++){
            if (a[i]>1){
                cnt1++;
                cntr-=a[i];
                vr--;
                a[i]=1;
            }
        }
        set<int> left;
        FOR(n)
            if (a[i]==1)
                left.insert(i);
        vector<pi> edges;
        int prev=-1;
        for (int i=1;i<=n;i++){
            if (a[i-1]>1){
                if (prev!=-1){
                    edges.pb(make_pair(prev,i));
                    a[prev-1]--;
                    a[i-1]--;
                }
                prev=i;
            }
        }
        int used=0;
        int single=0;
        FOR(n) if (left.find(i) == left.end() && a[i]>=2) single=i;
        FOR(n){
            if (used==2) break;
            if (edges.size()==0){
                if (vr==1){
                    if (1!=single && 2!=single){
                        edges.push_back(mp(2,single+1));
                        edges.push_back(mp(3,single+1));
                        a[1]=a[2]=0;
                        left.erase(1);
                        left.erase(2);
                    }
                    else if(0!=single && 2!=single){
                        edges.push_back(mp(1,single+1));
                        edges.push_back(mp(single+1,3));
                        a[0]=a[2]=0;
                        left.erase(2);
                        left.erase(0);
                    }
                    else{
                        edges.push_back(mp(single+1,1));
                        edges.push_back(mp(single+1,2));
                        a[0]=a[1]=0;
                        left.erase(0);
                        left.erase(1);
                    }
                    a[single]-=2;
                }
                else{
                    edges.push_back(mp(1,2));
                    left.erase(0);
                    left.erase(1);
                    a[0]=a[1]=0;
                }
                break;
            }
            else if (left.find(i)!=left.end()){
                if (used){
                    a[edges[edges.size()-1].S-1]--;
                    edges.push_back(mp(edges[edges.size()-1].S,i+1));
                }
                else{
                    a[edges[0].F-1]--;
                    edges.insert(edges.begin(),mp(i+1,edges[0].F));
                }
                left.erase(i);
                a[i]--;
                ++used;
            }
        }
        for (int i=0;i<n;i++){
            if (left.find(i) == left.end() && a[i]>0){
                while (a[i]>0 && left.size()>0){
                    int v=*left.begin();
                    edges.push_back(mp(i+1,v+1));
                    left.erase(v);
                    a[v]=0;
                    a[i]--;
                }
            }
        }
        cout<<"YES"<<' '<<vr+1<<endl;
        cout<<edges.size()<<endl;
        for (auto x: edges){
            cout<<x.F<<' '<<x.S<<endl;
        }
    }
}
void precompute(){
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(15);
    precompute();
    int t=1;
    while (t--){
        solve();
        
    }
}
