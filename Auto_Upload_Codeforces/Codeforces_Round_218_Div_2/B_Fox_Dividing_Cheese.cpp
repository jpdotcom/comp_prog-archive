#include <bits/stdc++.h>
using namespace std;

map<pair<long long,long long>,long long>cache;

int f(long long a,long long b){
    
    int val[4]={1,2,3,5};
  
    pair<long long,long long>p;
    pair<long long, long long>p2;
    p=make_pair(a,b);
    p2=make_pair(b,a);
    if (a==b){
        return 0;}
    else if (cache.find(p)!=cache.end()){
        
        return cache[p];}
    else{
        long long ans= 1000000000;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                int val1,val2;
               
                val1=val[i];
                val2=val[j];
                if (val1==1 && val2==1){
                    continue;}
                
                
                else if (a%val1==0 && b%val2==0) {
                    
                    long long inc=(val1!=1 && val2!=1) ? 2:1;
                    long long newa=a/val1;
                    long long newb=b/val2;
                    ans=min(ans,inc+f(newa,newb));
                    

                }

                }}
            cache[p]=ans;
            cache[p2]=ans;
              return ans;}
          }
int main(){
    long long a,b;
    cin>>a;
    cin>>b;
    
    long long res=f(a,b);
   
    if (res==1000000000){
        cout<<-1;}
    else{
        cout<<res;}
    return 0;
}

