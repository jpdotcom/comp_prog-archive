#include <iostream>
#include <string>
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
#include <iomanip> 
#include <cmath>
using namespace std;
//1372ms    300KB
#include <cstdio>
#include <algorithm>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100010
#define LL __int64
 
struct node
{
    int x,y;
}nd[N];
vector<int> x[N],y[N];
int n,ans;
LL hashnode[N];
 
bool cmpx(node fa,node fb)
{
    if(fa.x==fb.x) return fa.y<fb.y;
    return fa.x<fb.x;
}
 
bool cmpy(node fa,node fb)
{
    if(fa.y==fb.y) return fa.x<fb.x;
    return fa.y<fb.y;
}
 
int main()
{
    int i,l,r,u,d,idx,idy,sx,sy,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&nd[i].x,&nd[i].y);
        hashnode[i]=(LL)nd[i].x*200000+nd[i].y;
    }
    sort(nd+1,nd+n+1,cmpx);
    for(i=1;i<=n;i++) x[nd[i].x].push_back(nd[i].y);
    sort(nd+1,nd+n+1,cmpy);
    for(i=1;i<=n;i++) y[nd[i].y].push_back(nd[i].x);
    hashnode[n+1]=(1ULL<<63)-1;
    sort(hashnode+1,hashnode+n+1);
    for(i=1;i<=n;i++)
    {
        d=nd[i].x;
        l=nd[i].y;
        idx=lower_bound(x[d].begin(),x[d].end(),l)-x[d].begin()+1;
        idy=lower_bound(y[l].begin(),y[l].end(),d)-y[l].begin()+1;
        sx=x[d].size();
        sy=y[l].size();
        while(idx<sx&&idy<sy)
        {
            u=y[l][idy];
            r=x[d][idx];
            if(u-d==r-l)
            {
                tmp=lower_bound(hashnode+1,hashnode+n+2,(LL)u*200000+r)-hashnode;
                if(hashnode[tmp]==(LL)u*200000+r) ans++;
                idx++;
                idy++;
            }
            else if(u-d<r-l) idy=lower_bound(y[l].begin(),y[l].end(),d-l+r)-y[l].begin();
            else if(u-d>r-l) idx=lower_bound(x[d].begin(),x[d].end(),l-d+u)-x[d].begin();
        }
    }
    printf("%d\n",ans);
    return 0;
}
