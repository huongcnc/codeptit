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
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m-1;j++){
				if(a[i][j]==0) continue;
				int i1=i+1,j1=j+1,dem=1;
				while(i1!=n&&j1!=m&&a[i1][j1]==1){
					int check=1;
					for(int k=j;k<=j1;k++){
						if(a[i1][k]==0) {
							check=0;
							break;
						}
					}
					if(!check) break;
					for(int k=i;k<=i1;k++){
						if(a[k][j1]==0) {
							check=0;
							break;
						}
					}
					if(!check) break;
					dem++,i1++,j1++;
				}
				if(max<dem) max=dem;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
