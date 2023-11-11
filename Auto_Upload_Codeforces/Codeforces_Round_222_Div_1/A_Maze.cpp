#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#define FOR(a,b) for (int i=a;i<b;++i)
typedef long long ll;
using namespace std;
const int maxN=505;
int n,m,k;
int arr[maxN][maxN];
int visited[maxN][maxN];
vector<vector<int>> have;
int dfs(int u,int v, int cnt){
    if (visited[u][v] || cnt==k) return cnt;
    cnt++;
    visited[u][v]=1;
    if (u!=0 && arr[u-1][v])
        cnt=dfs(u-1,v,cnt);
    if (u!=n-1 && arr[u+1][v])
        cnt=dfs(u+1,v,cnt);
    if (v!=0 && arr[u][v-1])
        cnt=dfs(u,v-1,cnt);
    if (v!=m-1 && arr[u][v+1])
        cnt=dfs(u,v+1,cnt);
    return cnt;
}
void solve(){
    cin>>n>>m>>k;
    int u,v;
    int val=0;
    for (int i=0;i<n;i++){
        int j=0;
        string s; cin>>s;
        for (int j=0;j<m;j++){
            arr[i][j]=(s[j]=='.' ? 1 : 0);
            if (arr[i][j]){
                u=i;
                v=j;
                val++;
            }
        }
    }
    k=val-k;
    dfs(u,v,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!visited[i][j] && arr[i][j]==1){
                arr[i][j]=2;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (arr[i][j]==0)
                cout<<'#';
            if (arr[i][j]==1)
                cout<<'.';
            if (arr[i][j]==2)
                cout<<'X';
        }
        cout<<endl;
    }
}
int main(){
    int t=1;
    while (--t){
        solve();
    }
    solve();
    return 0;
}
