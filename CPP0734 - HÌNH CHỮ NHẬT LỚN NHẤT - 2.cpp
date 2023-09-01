#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[500][500];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int max=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==0) continue;
				int j1=j;
				while(j1!=m&&a[i][j1]==1){
					int i1=i;
					while(i1!=n&&a[i1][j]==1){
						int check=1;
						for(int k=j;k<=j1;k++){
							if(a[i1][k]==0) {
								check=0;
								break;
							}
						}
						if(check==0) break;
						i1++;
					}
					j1++;
					int dem=(j1-j)*(i1-i);
					if(max<dem) max=dem;
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
