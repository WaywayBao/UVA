#include<iostream>
using namespace std;

int main(){
	int N,D;
	while((cin>>N>>D)&&(N||D)){
		int mul[27]={1},index=26;
		while(D--){
			for(int i=0,carry=0;i<27;i++){
				mul[i]=mul[i]*N+carry;
				carry=mul[i]/10;
				mul[i]%=10;
			}
		}
		while(!mul[--index]);
		for(int i=index;i>=0;i--)
			cout<<mul[i];
		cout<<endl;
	}
	return 0;
} 
