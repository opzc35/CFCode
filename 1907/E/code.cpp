#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int cnt;
int digsum(int x){
	int sum = 0;
	while(x){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

void work(){
	cin>>n;
	cnt = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			int k = n-i-j;
			if(digsum(i) + digsum(j) + digsum(k) == digsum(n)){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}


signed main(){
	cin>>T;
	while(T--){
		work();
	}
}