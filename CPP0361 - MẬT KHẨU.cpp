#include<bits/stdc++.h>
using namespace std;
struct huong{
	vector<string> v;
};
bool check(string s, string a){
	int x=s.size(),y=a.size();
	for(int i=0;i<=x-y;i++){
		string s1(s.begin()+i,s.begin()+i+a.size());
		if(a==s1) return true;
	}
	return false;
}

int main(){
		int n;
		cin>>n;
		map<string,int> m;
		int max=0;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			if(max<s.size()) max=s.size();
			m[s]++;
		}
		int dem=0;
		huong a[11];
		for(map<string,int>::iterator i=m.begin();i!=m.end();i++){
			a[i->first.size()].v.push_back(i->first);
		}
		for(int i=1;i<=9;i++){
			for(int j=i+1;j<=10;j++){
				for(int i1=0;i1<a[i].v.size();i1++){
					for(int j1=0;j1<a[j].v.size();j1++){
						if(check(a[j].v[j1],a[i].v[i1])) dem+=m[a[j].v[j1]]*m[a[i].v[i1]];
					}
				}
			}
		}
		for(map<string,int>::iterator i=m.begin();i!=m.end();i++){
			dem+=(i->second)*(i->second-1);
		}
		cout<<dem<<endl;


	return 0;
}
