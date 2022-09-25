#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>s)&1LL)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18+7)
using namespace std;
using namespace __gnu_pbds;
const int maxN=5e6+1;
int a[maxN];
int cnt[maxN];
map<int,pi> vals;
int b[maxN];
int n;
int find(int val,int i,int p[]){
    for (int k=i;k<n;k++){
        if (p[k]==val){
            return k;
        }
    }

}
void solve(){
    cin>>n;
    int v1=-1,v2=-1,v3=-1;
    FOR(n){
        cin>>a[i];
        cnt[a[i]]++;
        if (cnt[a[i]]>=2 && v1!=a[i]){
            if (v1==-1) v1=a[i];
            else v2=a[i];
        }
        if (cnt[a[i]]>=4) v3=a[i];
    }
    if (v3!=-1){
        print("YES");
        for (int i=0,c=0;i<n && c!=4;i++){
            if (a[i]==v3){
                cout<<i+1<<' ';
                c++;
            }
        }
        return;
    }
    else if (v1!=-1 && v2!=-1){
        print("YES");
        vi x1,x2;
        FOR(n){
            if (a[i]==v1 && x1.size()<2) x1.pb(i+1);
            if (a[i]==v2 && x2.size()<2) x2.pb(i+1);
        }
        cout<<x1[0]<<' '<<x2[0]<<' '<<x1[1]<<' '<<x2[1];
        return;
    }
    else{
        if (v1!=-1){

            FOR(n) b[i]=a[i];
            sort(b,b+n);
            int i=0,j=n-1;
            while (i<j && b[i]<v1 && b[j]>v1){
                if (b[i]+b[j]==2*v1){
                    print("YES");
                    int i1=find(v1,0,a);
                    int i2=find(v1,i1+1,a);
                    int i3=find(b[i],0,a);
                    int i4=find(b[j],0,a);
                    cout<<i1+1<<' '<<i2+1<<' '<<i3+1<<' '<<i4+1<<endl;
                    return;
                }
                else if (b[i]+b[j]>2*v1) j--;
                else i++;
            }
        }
        int ok=0;
        for (int i=0;i<n;i++){
            if (a[i]!=v1 || !ok){
                if (v1!=-1) ok|=(a[i]==v1);
            for (int j=i+1;j<n;j++){
                if (a[j]!=v1 || !ok){
                if (vals.find(a[i]+a[j])==vals.end()) vals[a[i]+a[j]]=mp(i+1,j+1);
                else{
                    int s=a[i]+a[j];
                    print("YES");
                    cout<<vals[s].F<<' '<<vals[s].S<<' '<<i+1<<' '<<j+1<<endl;
                    return;
                }
                }
                if (v1!=-1) ok|=(a[j]==v1);
            }
            }
        }
    }
    print("NO");
    return;
}
void precompute(){
}
int main(){
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
