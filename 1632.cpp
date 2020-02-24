#include<iostream>
#define min(a,b) ((a)<(b)?(a):(b))
#define inf 0x3f3f3f3f
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int* location=new int[n+1];
		int* deadline=new int[n+1];
		int** dp_left=new int*[n+1];
		int** dp_right=new int*[n+1];
		for(int i=1;i<=n;i++){
			dp_left[i]=new int[n+1]();
			dp_right[i]=new int[n+1]();
			cin>>location[i]>>deadline[i];
		}
		for(int i=n-1;i>0;i--)
			for(int j=i+1;j<=n;j++){
				dp_right[i][j]=min(dp_right[i][j-1]+location[j]-location[j-1],dp_left[i][j-1]+location[j]-location[i]);
				if(dp_right[i][j]>=deadline[j])
					dp_right[i][j]=inf;
				dp_left[i][j]=min(dp_right[i+1][j]+location[j]-location[i],dp_left[i+1][j]+location[i+1]-location[i]);
				if(dp_left[i][j]>=deadline[i])
					dp_left[i][j]=inf;				
			}
		int ans=min(dp_right[1][n],dp_left[1][n]);
		if(ans>=inf)
			cout<<"No solution"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
} 
