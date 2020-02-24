#include<cstdio>		//uva10900 So you want to be a 2n-aire?
#define max(a,b) (a)>(b)?(a):(b)
double expect[31];

int main(){
	int n;
	double t;
	while(scanf("%d%lf",&n,&t)&&n+t!=0){
		if(t==1)
			expect[0]=1<<n;
		else{
			expect[n]=1<<n;
			for(int i=n-1;i>=0;--i){
				double p=max(t,(1<<i)/expect[i+1]);
				expect[i]=(p-t)/(1-t)*(1<<i)+(1-(p-t)/(1-t))*((p+1)/2.0)*expect[i+1];
			}
		}
		printf("%.3f\n",expect[0]);
	}
	return 0;
}


