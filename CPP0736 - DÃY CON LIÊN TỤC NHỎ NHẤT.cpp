#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		int *a=new int[n];
		int max=0,tong=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>max) max=a[i];
			tong+=a[i];
		}
		if(max>x) {
			cout<<"1\n";
			continue;
		}
		if(tong <=x) {
			cout<<"-1\n";
			continue;
		}
		int min=n+1;
		for(int i=0;i<n;i++){
			int sum=0,j=i;
			while(sum<=x&&j!=n) sum+=a[j++];
			if(j!=n&&min>j-i) min=j-i; 
		}
		if(min==n+1) cout<<"-1\n";
		else cout<<min<<endl;
	}
	return 0;
}
