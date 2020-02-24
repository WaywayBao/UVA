#include<iostream>
using namespace std;
long long Fibo[50]={1,1};
string BFS[30]={"0","1"};

char FiboPosition(long n,long position){
	if(n<30)
		return BFS[n][position];
	if(position<Fibo[n-2])
		return FiboPosition(n-2,position);
	return FiboPosition(n-1,position-Fibo[n-2]);
}

int main(){
	for(int i=2;i<50;i++) Fibo[i]=Fibo[i-2]+Fibo[i-1];
	for(int i=2;i<30;i++) BFS[i]=BFS[i-2]+BFS[i-1];
	long testcase,N,i,j;
	cin>>testcase;
	while(testcase--){
		cin>>N>>i>>j;
		if(N<30){
			for(int s=i;s<=j;s++) 
				cout<<BFS[N][s];
		}else{
			if(N>47) N=48-N%2;
			for(long s=i;s<=j;s++) cout<<FiboPosition(N,s);
		}
		cout<<endl;
	}
	return 0;
}
