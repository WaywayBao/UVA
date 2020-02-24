#include<iostream>		//uva 10080 Gopher 2
#include<cstring>
using namespace std;

struct Point{
	double x,y;
}gopher[101],hole[101];

bool reach[101][101],visit[101];
int match[101],n,m,s,v,ans;

bool DFS(int k){
	for(int i=0;i<m;++i){
		if(!visit[i]&&reach[k][i]){
			visit[i]=true;
			if(match[i]==-1||DFS(match[i])){
				match[i]=k;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(cin>>n>>m>>s>>v){
		memset(match,-1,sizeof(match));
		for(int i=0;i<n;++i) 
			cin>>gopher[i].x>>gopher[i].y;
		for(int i=0;i<m;++i) 
			cin>>hole[i].x>>hole[i].y;
		int time=(s*v)*(s*v);		//time square 
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			reach[i][j]=((gopher[i].x-hole[j].x)*(gopher[i].x-hole[j].x)+(gopher[i].y-hole[j].y)*(gopher[i].y-hole[j].y))<=time;
		ans=0;
		for(int i=0;i<n;++i){
			memset(visit,false,sizeof(visit));
			if(!DFS(i)) ++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}
