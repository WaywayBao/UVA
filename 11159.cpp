#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;
int A[MAX],B[MAX],M[MAX],m,n;
bool judge[MAX][MAX],visit[MAX];
		
bool DFS(int i){
	for(int j=1;j<=m;j++){
		if(judge[i][j]&&!visit[j]){
			visit[j]=true;
			if(!M[j]||DFS(M[j])){
				M[j]=i;
				return true;
			}
		}
	}
	return false;
} 

int main(){
	int testcase;
	cin>>testcase;
	for(int s=1;s<=testcase;s++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>A[i];
		cin>>m;
		for(int i=1;i<=m;i++)
			cin>>B[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				judge[i][j]=(A[i]&&B[j]%A[i]==0)||!(A[i]||B[j]);
		int ans=0;
		memset(M,0,sizeof(M));
		for(int i=1;i<=n;i++){
			memset(visit,false,sizeof(visit));
			if(DFS(i)) ans++;
		}
		cout<<"Case "<<s<<": "<<ans<<endl;
	}
	return 0;
} 


