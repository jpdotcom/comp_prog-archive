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
#define FOR(a,b) for (int i=a;i<b;++i)
using namespace std;
    

int main(){
    
    string s;
    getline(cin,s);
    
    int n=s.size();
    int flip[n]={0};
    int last_idx;
    for (int i=0;i<(n-1);i++){

        if (s[i]=='b'&& s[i+1]=='a'){
            flip[i]=1;
            last_idx=i+1;
            for (int j=i+1;j<n;j++){
                if (s[j]=='a'){
                    last_idx=j;}
                else{
                    flip[last_idx]=1;
                    break;}}
            flip[last_idx]=1;

        
        
    }}

    for (int x:flip){
        cout<<x<<' ';}
    return 0;

    }
