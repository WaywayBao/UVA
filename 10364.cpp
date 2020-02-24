#include<iostream> 		//uva10364
#include<algorithm>
using namespace std;
int stick[20],N,M,total;
bool used[20];

bool DFS(int num,int cur_len,int cur_idx){
	if(num == 3) return true;
	if(cur_len == total/4)
		return DFS(num+1,0,0);
	for(int i=cur_idx;i<M;++i){
		if(!used[i] && cur_len+stick[i] <= total/4){
			used[i]=true;
			if(DFS(num,cur_len+stick[i],i+1))
				return true;
			used[i]=false;
		}
	}
	return false;
}

int main(){
	cin>>N;
	while(N--){
		cin>>M;
		total=0;
		for(int i=0; i<M; i++){
			cin>>stick[i];
			total+=stick[i];
			used[i]=false;
		}
		sort(stick,stick+M,greater<int>());
		if(total%4!=0 || stick[0]>total/4)
			cout<<"no"<<endl;
		else{
			if(DFS(0,0,0))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
	return 0;
}
