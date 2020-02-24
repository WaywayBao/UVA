#include<cstdio>		//uva 10664
using namespace std;

int main(){
	int m,n,sum,w;
	char temp;
	scanf("%d",&m);
	while(m--){
		bool dp[201]={true};
		sum=0;
		do{
			scanf("%d%c",&w,&temp);
			for(int j=200-w;j>=0;--j){
				if(dp[j])
					dp[j+w]=true;
			}
			sum+=w;
		}while(temp!='\n');
		if(sum%2!=0||!dp[sum/2])
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
} 
