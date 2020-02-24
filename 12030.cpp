#include<iostream>		//uva12030 Help the Winners
#include<cstring>
using namespace std;
long long state[1<<16][3];
int arr[16][16];
int t,n;

long long DFS(int visit,int level,int match){
	if(level>n)	return match>0;
	if(state[visit][match]!=-1) return state[visit][match];

	long long ANS=0;
	for(int i=1;i<=n;++i){
		if((visit&1<<i)==0){
			if(arr[level][i]==2){
				long long factorial=1;
				for(int i=1;i<=n-level;++i)
					factorial*=i;
				ANS+=factorial;
			}
			else
				ANS+=DFS(visit|1<<i,level+1,(match|arr[level][i])>=2?2:match&&arr[level][i]);
		}
	}
	state[visit][match]=ANS;
	return ANS;
}

//long long DFS(int visit,int level,int match,int super){
//	if(level>n)	return (super||match);
//	if(state[visit][match][super]!=-1) return state[visit][match][super];
//
//	long long ANS=0;	
//	for(int i=1;i<=n;++i){
//		if((visit&1<<i)==0){
//			ANS+=DFS(visit|1<<i,level+1,arr[level][i]&&match,arr[level][i]==2||super);
//		}
//	}
//	state[visit][match][super]=ANS;
//	return ANS;
//}	

int main(){
	cin>>t;
	for(int cas=1;cas<=t;++cas){
		memset(state,-1,sizeof(state));
		cin>>n;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>arr[i][j];
		cout<<"Case "<<cas<<": "<<DFS(1,1,1)<<endl;
	}
	return 0;
}

