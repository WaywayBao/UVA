#include<iostream>		//uva481 (LIS)
using namespace std;
int input[500001];
int trace[500001];
int min_len[500001];

void output(int i){
	if(i){
		output(trace[i]);
		cout<<input[i]<<endl;
	}
}
int main(){
	int cnt=1,max_len=1;
	while(cin>>input[cnt]) ++cnt;
	min_len[1]=1;
	for(int i=2;i<cnt;++i){
		int left=1,right=max_len+1,mid;
		while(left<right){		//Binary search
			mid=(left+right)/2;
			if(input[min_len[mid]]<input[i])
				left=mid+1;
			else
				right=mid;
		}
		min_len[right]=i;
		trace[i]=min_len[right-1];
		if(right>max_len) max_len=right;
	}
	cout<<max_len<<"\n-"<<endl;
	output(min_len[max_len]);
	return 0;
}
