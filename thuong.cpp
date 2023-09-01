#include<bits/stdc++.h>
using namespace std;

void dao(string &s){
	for(int i=0;i<s.size()/2;i++){
		char temp=s[i];
		s[i]=s[s.size()-i-1];
		s[s.size()-i-1]=temp;
	}
	return;
}
void bs0(string &s){
	int i=0;
	while(s[i]=='0') i++;
	while(s[i]=='-') i++;
	string s1(s.begin()+i,s.end());
	s=s1;
	return;
}
string nhan(string s,int n){
	string s1;
	int du=0;
	for(int i=s.size()-1;i>=0;i--){
		int sum=(s[i]-'0')*n+du;
		du=sum/10;
		s1+=sum%10+'0';
	}
	if(du!=0) s1+=du+'0';
	dao(s1);
	return s1;
}

int ss(string a,string b){
	if(a==b) return 2;
	if(a.size()>b.size()) return 1;
	if(a.size()<b.size()) return 0;
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;
	}
}

string hieu(string a,string b){
	if(a==b) return "0";
	if(ss(a,b)==0) {
		string temp=a;
		a=b;
		b=temp;
	}
	dao(a),dao(b);
	string s;
	int du=0;
	for(int i=0;i<a.size();i++){
		if(i>=b.size()){
			if(a[i]=='0'&&du==1) s+='9';
			else {
				s+=a[i]-du;
				du=0;
			}
		} else {
			int hieu=a[i]-b[i]-du;
			if(hieu>=0) {
				s+=hieu+'0';
				du=0;
			} else {
				s+=hieu+'0'+10;
				du=1;
			}
		}
	}
	dao(s);
	bs0(s);
	return s;
}
string thuong(string a, string b){
	int dem=0;
	if(a[0]=='-') {
		dem++;
		bs0(a);
	}
	if(b[0]=='-'){
		dem++;
		bs0(b);
	}
	if(a==b&&dem%2==0) return "1";
	if(a==b&&dem%2!=0) return "-1";
	if(ss(a,b)==0) return "0";
	string s,s1;
	for(int i=0;i<a.size();i++){
		if(s1!="0"||a[i]!='0') s1+=a[i];
		if(ss(s1,b)==0) s+='0';
		else {
			if(s1=="0") {
				s+='0';
			} else {
			int k=9;
			string s2=nhan(b,k);
			while(ss(s1,s2)==0) {
				k--;
				s2=nhan(b,k);
			}
			s+=k+'0';
			s1=hieu(s1,s2);
			}
		}
	}
	bs0(s);
	if(dem%2!=0) {
		dao(s);
		s+='-';
		dao(s);
	}
	return s;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<thuong(a,b)<<endl;
	}
	return 0;
}
