#include<iostream>		//uva 12075
using namespace std;
long long dp[1001][1001];

int GCD(int a,int b){	
	int temp;
	while(a%b!=0){
		temp=b;
		b=a%b;
		a=temp;
	}
	return b;
}

long long C(int m,int n){
	long long ans=m;
	for(int i=2;i<=n;++i)
		ans=ans*(m-i+1)/i;
	return ans;
}

int main(){	
	int M,N,cas=0;
	for(int i=2;i<=1000;++i)		//initial dp 
	for(int j=2;j<=i;++j)
		dp[j][i]=dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+GCD(i,j)-1;

	for(int i=2;i<=1000;++i)
	for(int j=2;j<=i;++j)
		dp[j][i]=dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

	long long ans;
	while((cin>>M>>N)&&M+N!=0){
		M++,N++;
		ans=C(M*N,3)-(dp[M-1][N-1]*2+C(M,3)*N+C(N,3)*M);
		cout<<"Case "<<++cas<<": "<<ans<<endl;
	}
	return 0;
}


/*#include<iostream>		// Indent
using namespace std;
long long dp[1001][1001];
int GCD(int a,int b){return (a%b==0?b:GCD(b,a%b));}
long long C(int m,int n){
	long long ans=m;
	for(int i=2;i<=n;++i)
		ans=ans*(m-i+1)/i;
	return ans;
}
int main(){
	int M,N,cas=0;
	for(int i=2;i<=1000;++i)
	for(int j=2;j<=1000;++j)
		dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+GCD(i,j)-1;
	for(int i=2;i<=1000;++i)
	for(int j=2;j<=1000;++j)
		dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
	while((cin>>M>>N)&&M+N!=0)
		cout<<"Case "<<++cas<<": "<<C((++M)*(++N),3)-(dp[M-1][N-1]*2+C(M,3)*N+C(N,3)*M)<<endl;
	return 0;
}*/
