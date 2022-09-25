#include <bits/stdc++.h>
#define FOR(b) for (int i=0;i<b;i++)
#define endl '\n';
#define F first
#define S second 
#define mp make_pair
#define print(x) cout<<x<<'\n'
#define pb push_back 
#define MOD (ll)1e9+7
#define bit(x,y) ((x>>y)&1)
typedef std::vector<int> vi;
typedef std::pair<long long, long long> pi;
typedef long long ll;
using namespace std;
int l[26];
int r[26];
int mult[26];
int seen[26];
string check(string a1, string a2){
    int v=0;
    string ans="";
    for (int i=0;i<(int)a2.size();i++){
        for (int j=0;j<(int)a1.size();j++){
            if (!(bit(v,a1[j]-'a'))) ans+=a1[j];
        }
        v^=(1<<(a2[i]-'a'));
    }
    return ans;
}
void solve(){
    string s; cin>>s;
    FOR(26) seen[i]=mult[i]=l[i]=r[i]=0;
    vi vals;
    string a1="",a2="";
    for (int i=(int)s.size()-1;i>=0;i--){
        if (!seen[s[i]-'a']){
            vals.pb(s[i]-'a');
            seen[s[i]-'a']=1;
            a1+=s[i];
        }
        r[s[i]-'a']++;
    }
    reverse(a1.begin(),a1.end());
    reverse(vals.begin(),vals.end());
    FOR((int) vals.size()) mult[vals[i]]=i+1;
    for (int i=0;i<(int)s.size();i++){
        int c=s[i]-'a';
        a2+=s[i];
        l[c]++;
        r[c]--;
        bool ok=true;
        for (int j=0;j<26;j++) if ((l[j]*mult[j])!=(l[j]+r[j])) ok=false;
        if (ok){
            break;
        }
    }
    if (check(a2,a1)==s){
        cout<<a2<<' '<<a1<<endl;
    }
    else{
        print(-1);
    }

}
void precompute(){
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
}
