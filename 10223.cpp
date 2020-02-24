#include<iostream>
#include<map>
using namespace std;
int main(){
	map<long long,int> tree;
	long long node[21]={1},ll;
	for(int i=1;i<=20;i++){
		for(int j=i-1,k=0;k<i;j--,k++)
			node[i]+=node[j]*node[k];
		tree[node[i]]=i;
	}
	while(cin>>ll)	cout<<tree[ll]<<endl;
	return 0;
}
