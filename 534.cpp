#include<cstdio>
#include<cmath>
double x[201], y[201];
double distance[201][201];
 
int main(){
	int n,cas=0;
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&x[i],&y[i]);
		for(int i=0;i<n;++i)
		for(int j=0;j<i;++j)
			distance[i][j]=distance[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));

		for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			double max=distance[i][k]>distance[k][j]?distance[i][k]:distance[k][j];
			if (distance[i][j]>max) 
				distance[i][j]=max;
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++cas,distance[0][1]);
	}
    return 0;
}
