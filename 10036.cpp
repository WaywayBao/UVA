#include<iostream>		//Divisibility
#include<cmath>
using namespace std;

int main(){
	int cas,N,K,num;
	cin>>cas;
	while(cas--){
		cin>>N>>K;
		bool arr[10001][100]={false};
		cin>>num;
		num=abs(num);
		arr[1][num%K]=true;
		for(int i=2;i<=N;++i){
			cin>>num;
			num %= K;
			num=abs(num);
			for(int j=0;j<K;++j)
				if(arr[i-1][j])
					arr[i][(j+num)%K] = arr[i][(j-num+K)%K] = true;
		}
		if(arr[N][0]) cout<<"Divisible"<<endl;
		else cout<<"Not divisible"<<endl;
	}
	return 0;
} 
