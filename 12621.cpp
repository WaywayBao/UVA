#include<iostream>
using namespace std;

int main(){
	int n,testcase,p,cal;
	cin>>testcase;
	while(testcase--){
		bool arr[500]={false};
		arr[0]=true;
		cin>>n>>p;
		n/=10;
		for(int i=0;i<p;i++){
			cin>>cal;
			cal/=10;
			for(int j=499-cal;j>=0;j--)
				if(arr[j])
					arr[j+cal]=true;
		}
		while(n<499&&!arr[n])
			n++;
		if(n==499)
			cout<<"NO SOLUTION"<<endl;
		else
			cout<<n*10<<endl;
	}
	return 0;
} 


