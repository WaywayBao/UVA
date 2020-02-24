#include<iostream>		//uva1650
#define mod 1000000007
using namespace std;
long long dp[1005][1005],sum[1005][1005];

int main(){
	string str;
	while(cin>>str){
		int n=str.length()+1;
		dp[1][1]=sum[1][1]=1;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=i;j++){
				if(str[i-2]=='I')
					dp[i][j]=sum[i-1][j-1];
				else if(str[i-2]=='D') 
					dp[i][j]=sum[i-1][i-1]-sum[i-1][j-1];
				else		// '?'='I'+'D'
					dp[i][j]=sum[i-1][i-1];
				sum[i][j]=(dp[i][j]+sum[i][j-1])%mod;
			}
		cout<<(sum[n][n]+mod)%mod<<endl;
	}
	return 0;
}
