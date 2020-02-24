#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	vector<int> x(1,1);
	for(int i=1;i<=1000000;i++)
		x.push_back((x[(int)(i-sqrt(i))]+x[(int)log(i)]+x[(int)(i*sin(i)*sin(i))])%1000000);
	int i;		// 0<=i<=1000000
	while((cin>>i)&&i!=-1)
		cout<<x[i]<<endl;
	return 0;
}
