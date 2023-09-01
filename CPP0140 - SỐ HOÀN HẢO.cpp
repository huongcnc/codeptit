#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n>pow(10,12)) {
		    cout<<"0"<<endl;
		    continue;
		}
		long long sum=1;
		for(int i=2;i<sqrt(n);i++){
			if(n%i==0) sum+=i+n/i;
		}
		if(n==sqrt(n)*sqrt(n)) sum+=sqrt(n);
		if(sum==n) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	return 0;
}
