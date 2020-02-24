#include <iostream>		//uva 10154	Weights and Measures
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 5608
using namespace std;

int arr[N];
struct Turtle{
	int w, s;		//weighing and strength
}turtle[N];

int main(){
	int cnt=1;		//turtle number
	while(cin>>turtle[cnt].w>>turtle[cnt].s) ++cnt;
	sort(turtle+1,turtle+cnt,[](const Turtle& a, const Turtle& b){
		return a.s < b.s;
	});
	for(int i=1;i<cnt;++i){		//DP
		arr[i]=INF;
		for(int j=i;j>0;--j){
			if(arr[j-1]+turtle[i].w<=turtle[i].s && arr[j-1]+turtle[i].w<arr[j])
				arr[j]=arr[j-1]+turtle[i].w;
		}
	}
	int h=cnt-1;	//height
	while(arr[h] == INF) --h;
	cout<<h<<endl;
	return 0;
}




//2D array DP
/*#include <iostream>		//uva 10154	Weights and Measures
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 5608
using namespace std;

struct Turtle{
	int w, s;		//weighing and strength
}turtle[N];

int arr[N][N];

int main(){
	int cnt=1;		//turtle number
	while(cin>>turtle[cnt].w>>turtle[cnt].s) ++cnt;
	sort(turtle+1,turtle+cnt,[](const Turtle& a, const Turtle& b){
		if(a.s==b.s)
			return a.w > b.w;
		return a.s < b.s;
	});

	for(int i=0;i<cnt;++i)
	for(int j=1;j<=cnt;++j)
		arr[i][j]=INF;
		
	for(int i=1;i<cnt;++i)
	for(int j=1;j<=i;++j){
		arr[i][j] = arr[i-1][j];
		if(arr[i-1][j-1]+turtle[i].w<=turtle[i].s)
			arr[i][j]=min(arr[i][j],arr[i-1][j-1]+turtle[i].w);
	}
		
	int h=cnt-1;	//height
	while(arr[cnt-1][h]==INF) --h;
	cout<<h<<endl;
	return 0;
}*/
