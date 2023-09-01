#include <iostream>
#include <algorithm>
using namespace std;

int xcy(int x,int y){
	if(y>x/2) y=x-y;
	long long a=1;
	for(int i=x;i>x-y;i--){
		a=a*i;
	}
	for(int i=2;i<=y;i++){
		a=a/i;
	}
	return a;
}
long long huong(int r,int b,int g,int n){
	return (long long)(xcy(n,r)*xcy(n-r,b)*xcy(n-r-b,g));
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n,r,b,g;
		cin>>n>>r>>b>>g;
		long long sum=0;
		for(int i=r;i<=n;i++){
			for(int j=b;j<=n-i;j++){
				int k=n-i-j;
				if(k<g) break;
				sum+=huong(i,j,k,n);
			}
		}
		cout<<sum<<endl;
    }

    return 0;
}
