#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while (t--){
	    int a,b; cin>>a>>b;
	    cout<<max(0,a-b)<<endl;
	}
	return 0;
}
