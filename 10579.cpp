#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> V;
	vector<int> v1;
	vector<int> v2;
	v1.push_back(1);	//f(1)=1
	v2.push_back(1);	//f(2)=1
	
	V.push_back(v1);	//V[0]
	V.push_back(v2);	//V[1]
	for(int i=2;i<=5000;i++){
		vector<int> temp;
		for(int j=0;j<V[i-1].size();j++)
			temp.push_back(V[i-1][j]);
		for(int k=0;k<V[i-2].size();k++){
			temp[k]+=V[i-2][k];
			if(temp[k]>=10){
				temp[k]%=10;
				if(k==V[i-1].size()-1)
					temp.push_back(1);
				else
					temp[k+1]+=1;
			}
		}
		V.push_back(temp);
	}
	int f;
	while(cin>>f){
		for(int s=V[f-1].size()-1;s>=0;s--)
			cout<<V[f-1][s];
		cout<<endl;
	}
	return 0;
} 
