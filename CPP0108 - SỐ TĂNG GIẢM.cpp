#include<bits/stdc++.h>
using namespace std;
bool snt(string s){
	long long sum=0,k=1;
	for(int i=s.size()-1;i>=0;i--){
		sum+=k*(s[i]-'0');
		k*=10;
	}
	for(int i=2;i<=sqrt(sum);i++){
		if(sum%i==0) return false;
	}
	return sum>1;
}
void huong(int n){
	if(n==1) {
		cout<<"5"<<endl;
		return;
	}
	int dem=0;
	string s;
	for(int i=1;i<=n;i++){
		s+=i+'0';
	}
	while(s[0]!='9'-n+1){
		if(snt(s)) dem++;
		int i=n-1;
		while(s[i]=='9'-n+i+1) i--;
		s[i]+=1;
		for(int j=i+1;j<n;j++){
			s[j]=s[i]+j-i;
		}
	}
	if(snt(s)) dem++;
	for(int i=0;i<n;i++){
		s[i]='9'-i;
	}
	while(s[0]!='0'+n-1){
		if(snt(s)) dem++;
		int i=n-1;
		while(s[i]=='0'+n-1-i) i--;
		s[i]-=1;
		for(int j=i+1;j<n;j++){
			s[j]=s[i]+i-j;
		}
	}
	if(snt(s)) dem++;
	cout<<dem<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		huong(n);
	}
    return 0;
}
