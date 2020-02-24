#include<iostream>		//uva12532 Interval Product
#include<cstring>
using namespace std;
int X[100001],sign[300001];
int N,K,idx,I,J,input;

int Sign(const int& a){
	if(a>0)	return 1;
	else if(a<0) return -1;
	else return 0;
}

void update(int node, int left, int right){
	if(left==right)
		sign[node]=X[idx];
	else{ 
		int mid=(left+right)/2;
		if(idx<=mid)
			update(node*2,left,mid);
		else
			update(node*2+1,mid+1,right);
		sign[node]=sign[node*2]*sign[node*2+1];
	}
}

int query(int node, int left, int right){
	if(I<=left&&right<=J)	return sign[node];
	int mid=(left+right)/2, ans=1;
	if(I<=mid)
		ans*=query(node*2,left,mid);
	if(mid<J)
		ans*=query(node*2+1,mid+1,right);
	return ans;
}

int main(){
	char letter;
	while(cin>>N>>K){
		memset(sign,1,sizeof(sign[0])*N*3);
		for(idx=1;idx<=N;++idx){
			cin>>input;
			X[idx]=Sign(input);
			update(1,1,N);
		}
		while(K--){
			cin>>letter>>I>>J;
			if(letter=='C'){
				idx=I, X[idx]=Sign(J);
				update(1,1,N);
			}else{
				int ans=query(1,1,N);
				if(ans==1)
					cout<<'+';
				else if(ans==-1)
					cout<<'-';
				else
					cout<<0;
			}
		}
		cout<<endl;
	}
	return 0;
}

