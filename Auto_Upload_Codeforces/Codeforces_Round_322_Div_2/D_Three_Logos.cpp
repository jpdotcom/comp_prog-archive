#include <bits/stdc++.h>
typedef long long ll;
#define FOR(n) for (int i=0;i<n;i++)
typedef std::pair<long long, long long> pi;
typedef std::vector<long long> vi;
#define PI  3.14159265358979323846
#define F first
#define S second
#define endl '\n'
#define print(x) cout<<x<<'\n'

using namespace std;

int power(long long x, unsigned int y, int p)
{
    unsigned long long res = 1;     // initialize result
 
    x = x % p; // update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // in case x is divisible by p;
 
    while (y > 0)
    {
        // if y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int op(int a,int b){
  return a+b;
}
const int N = 5;  // limit for array size
int n; // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = 2*N-1;i>=0;i--) t[i]=0; }

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = op(t[p],t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = op(res,t[l++]);
    if (r&1) res = op(res,t[--r]);
  }
  return res;
}
ll modu(ll a,ll b){
    return (b+(a%b)) % b;}
void precompute(){

}

    
void solve(){
  int arr[3][2];
  for (int i=0;i<3;i++){
    for (int j=0;j<2;j++){
      cin>>arr[i][j];
    }
  }
  vector<char> letters={'A','B','C'};
  for (int i=0;i<3;i++){
    for (int j=i+1;j<3;j++){
      for (int k=0;k<2;k++){
        for (int l=0;l<2;l++){
          int s1=arr[i][k];
          int s2=arr[j][l];
          int s3=abs(arr[i][k^1]-arr[j][l^1]);
          int s4=((arr[i][k^1]>arr[j][l^1])? s2: s1);
          int other=3-i-j;
          int c=((s3*s4==0 && (arr[other][0]==arr[i][k^1]||arr[other][1]==arr[i][k^1])) ? ((arr[other][0]!=arr[i][k^1]) ? arr[other][0] : arr[other][1]) : 0);
          int d=((c==0 && s3*s4==0 && (arr[other][0]==(s1+s2) || arr[other][1]==(s1+s2))) ? (arr[other][0]!=s1+s2 ? arr[other][0] : arr[other][1]) : 0);
          if (((arr[other][0]==s3 && arr[other][1]==s4) || c!=0 || d!=0) && ((s1+s2+c)==(max(arr[i][k^1],arr[j][l^1])+d))){
            char mat[s1+s2+c][max(arr[i][k^1],arr[j][l^1])+d];
            for (int a=0;a<s1+s2+c;a++){
              for (int b=0;b<max(arr[i][k^1],arr[j][l^1])+d;b++){
                mat[a][b]=' ';
              }
            }
            for (int a=0;a<s1;a++){
              for (int b=0;b<arr[i][k^1];b++){
                mat[a][b]=letters[i];
              }
            }
            for (int a=s1;a<s1+s2;a++){
              for (int b=0;b<arr[j][l^1];b++){
                mat[a][b]=letters[j];
              }
            }
            for (int a=0;a<s1+s2+c;a++){
              for (int b=0;b<max(arr[i][k^1],arr[j][l^1])+d;b++){
                if (mat[a][b]==' '){
                  mat[a][b]=letters[3-i-j];
                }
              }
            }
            print(s1+s2+c);
            for (int a=0;a<s1+s2+c;a++){
              for (int b=0;b<max(arr[i][k^1],arr[j][l^1])+d;b++){
                cout<<mat[a][b];
              }
              cout<<endl;
            }
            return;
          }
        }
      }
    }
  }
  print(-1);
  return;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  FOR(t){
    solve();
  }
  return 0;
}
    