#include<iostream>
using namespace std;

int main(){
	int T,total_weight,count=1;
	cin>>T;
	while(T--){
		int W[10];
		int N[5];
		total_weight=0;
		for(int i=0;i<10;i++){
			cin>>W[i];
			total_weight+=W[i];		//totalweight=4a+4b+4c+4d+4e
		}
		N[2]=total_weight/4-W[0]-W[9];
		N[0]=W[1]-N[2];
		N[1]=W[0]-N[0];
		N[4]=W[8]-N[2];
		N[3]=W[9]-N[4];
		cout<<"Case "<<count++<<":";
		for(int i=0;i<5;i++)
			cout<<" "<<N[i];
		cout<<endl;
	}
	return 0;
} 
