#include<iostream>		//uva 11237 Halloween treats
#include<cstring>
using namespace std;
int neighbour[100010],remainder[100010],record[100010];

int main(){
	int c,n;
	while((cin>>c>>n)&&c+n!=0){
		for(int i=1;i<=n;++i)
			cin>>neighbour[i];
		int i=0;
		memset(record,-1,sizeof(record));
		do{
			record[remainder[i]]=i;
			i++;
			remainder[i]=(remainder[i-1]+neighbour[i])%c;
		}while(record[remainder[i]]==-1&&i+1<=n);
		if(record[remainder[i]]!=-1)
			for(int j=record[remainder[i]]+1;j<=i;++j)
				cout<<j<<(j==i?"\n":" ");
		else
			cout<<"no sweets"<<endl;
	}
	return 0;
}
