#include<iostream>		//uva10032
#include<cstring>
using namespace std;
int w[101];
long long dp[23000];

int main(){
	int cas,n,sum,_sum;
	cin>>cas;
	while(cas--){
		sum=0;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>w[i];
			sum+=w[i];
		}
		_sum=sum/2;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n;++i)
			for(int j=_sum-w[i];j>=0;--j)
				dp[j+w[i]] |= (dp[j]<<1);		
		long long temp=1LL<<(n/2);
		if(n%2)
			while(!(dp[_sum]&temp)&&!(dp[_sum]&temp<<1)) --_sum;
		else
			while(!(dp[_sum]&temp)) --_sum;
		cout<<_sum<<" "<<sum-_sum<<endl;
		if(cas) cout<<endl;
	}
	return 0;
}
