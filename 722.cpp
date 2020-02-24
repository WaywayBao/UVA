#include<iostream>		//uva 722
#include<cstring>
using namespace std;
char arr[100][100];
bool visited[100][100];
int indexI,indexJ;
int cnt;

void DFS(int i,int j){
	if(i<1||i>indexI||j<1||j>indexJ||visited[i][j]||arr[i][j]=='1') return;
	visited[i][j]=true;
	++cnt;
	DFS(i-1,j);
	DFS(i,j-1);
	DFS(i+1,j);
	DFS(i,j+1);	
}

int main(){
	int M,i,j;
	char a;
	cin>>M;
	while(M--){
		cin>>i>>j;		
		indexI=0;
		getchar();
		while((a=getchar())&&(a=='1'||a=='0')){
			indexJ=0;
			arr[++indexI][++indexJ]=a;
			while((a=getchar())&&(a=='1'||a=='0'))
				arr[indexI][++indexJ]=a;
		}
		cnt=0;
		memset(visited,false,sizeof(visited));
		DFS(i,j);
		cout<<cnt<<endl;
		if(M) cout<<endl;
	}
	return 0;
}
