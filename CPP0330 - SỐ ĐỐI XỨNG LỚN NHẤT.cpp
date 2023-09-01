#include<bits/stdc++.h>
using namespace std;
string huong(string s){
	map<int,int> m;
	for(int i=0;i<s.size();i++){
		m[s[i]-'0']++;
	}
	int max=0,chan=0,t=0;
	for(auto x:m){
		if(x.second%2==0&&x.first>0) chan=1;
	}
	if(chan==0) m[0]=0;
	for(auto x:m){
		if(x.second&2!=0&&max<=x.second) {
			max=x.second;
			t=x.first;
		}
	}
	for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
		if(i->first!=t&&i->second&2!=0) i->second=0;
	}
	string s1;
	for(auto x:m){
		for(int i=0;i<x.second;i++){
			s1+='0';
		}
	}
	map<int,int>::iterator i=m.end(),l=m.begin();
	l--;
	i--;
	int j=0;
	for(i;i!=l;i--){
		while(i->second!=0&&i->first!=t){
			s1[j]=i->first+'0';
			s1[s1.size()-j-1]=s1[j];
			i->second-=2;
			j++;
		}
	}
	for(int k=j;k<s1.size()-j;k++){
		s1[k]=t+'0';
	}
	return s1;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<huong(s)<<endl;
	}
	return 0;
}
