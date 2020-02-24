#include<cstdio>
using namespace std;
const double a[11]={0.05,0.1,0.2,0.5,1,2,5,10,20,50,100};
int main(){
	double D;
	unsigned long long dp[6001]={1};
		for(int i=0;i<11;i++)
			for(int j=a[i]*20;j<=6000;j++)
				dp[j]+=dp[(int)(j-a[i]*20)];
	while(scanf("%lf",&D)&&D!=0)
		printf("%6.2lf%17lld\n",D,dp[(int)(D*20)]);
	return 0;
}
