#include<iostream>		//11003 Boxes
#include<algorithm>
using namespace std;
int dp[1001];

struct Box{
	int weight,load;
}box[1001];

int main(){
	int N;
	while(cin>>N&&N!=0){
		for(int i=N;i>0;--i)
			cin>>box[i].weight>>box[i].load;
		for(int i=1;i<=N;++i){
			dp[i]=0x3f3f3f3f;
			for(int j=i;j>0;--j){
				if(dp[j-1]<=box[i].load&&dp[j-1]+box[i].weight<dp[j])
						dp[j]=dp[j-1]+box[i].weight;
			}
		}
		int max=N;
		while(dp[max]==0x3f3f3f3f) --max;
		cout<<max<<endl;
	}
	return 0;
} 
