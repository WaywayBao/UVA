#include<iostream>
#include<vector>
using namespace std;

struct Work{
	Work(int T,int S,int position){
		time=T;
		fine=S;
		index=position;
	}
	int time;
	int fine;
	int index;
};

int main(){
	int testcase,N,S,T,index;
	cin>>testcase;
	while(testcase--){
		vector<Work> v;
		index=0;
		cin>>N;
		while(N--){
			cin>>T>>S;
			Work w(T,S,++index);			
			int i=v.size()-1;
			while(i>=0&&v[i].fine*T-v[i].time*S<=0){ 
				if(v[i].fine*T-v[i].time*S==0&&v[i].index<index)
					break;
				i--;
			}
			v.insert(v.begin()+i+1,w);
		}
		for(vector<Work>::iterator it=v.begin();it!=v.end();it++){
			cout<<(*it).index;
			if(it!=v.end()-1)
				cout<<" ";
		}
		cout<<endl;
		if(testcase)
			cout<<endl;
	}
	return 0;
}
