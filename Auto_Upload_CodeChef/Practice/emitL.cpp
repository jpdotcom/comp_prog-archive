#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
int main() {
	int t; cin>>t;
	while (t--){
	    map<int,int> cnt;
	    string s; cin>>s;
	    for (auto c: s) cnt[c]++;
	    if (s.size()==9){
	        int ans=cnt['L']==2 && cnt['T']==2 && cnt['I']==2 && cnt['M']==2 && cnt['E']==1;
	        if (ans) cout<<"YES"<<endl;
	        else cout<<"NO"<<endl;

	    }
	    else{
	        int ans= cnt['L']>=2 && cnt['T']>=2 && cnt['I']>=2 && cnt['M']>=2 && cnt['E']>=2;
    	    if (ans) cout<<"YES"<<endl;
    	    else cout<<"NO"<<endl;
	    }
	}
	return 0;
}
