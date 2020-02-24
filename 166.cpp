#include<cstdio>
const int coin[6]={1,2,4,10,20,40};		//original coin*20

int main(){
	int change[121]={0},own[6];
	for(int i=5;i>=0;--i)		//initial make change
		for(int k=1;k<=120/coin[i];++k)
			for(int j=120;j>=coin[i];--j)		//if j==coin or no solution for j or new solution is minmum answer
				if(j==coin[i]||(change[j-coin[i]]!=0&&(change[j]==0||change[j-coin[i]]+1<change[j])))
					change[j]=change[j-coin[i]]+1;
	while(true){
		int pay[121]={0},is_end=0,min=121,price;
		for(int i=0;i<6;++i){
			scanf("%d",&own[i]);
			is_end+=own[i];
		}
		if(is_end==0)	break;		//exit program
		double tempPrice;
		scanf("%lf",&tempPrice);
		price=(int)(tempPrice*20);		//type casting, convient for calculate
		for(int i=5;i>=0;--i)		//consumer pay
			for(int k=1;k<=own[i];++k)
				for(int j=120;j>=coin[i];--j)
					if(j==coin[i]||(pay[j-coin[i]]!=0&&(pay[j]==0||pay[j-coin[i]]+1<pay[j])))
						pay[j]=pay[j-coin[i]]+1;
		for(int i=price;i<=120;++i)		//decide minmum answer
			if(pay[i]!=0&&pay[i]+change[i-price]<min)
				min=pay[i]+change[i-price];
		printf("%3d\n",min);
	}
	return 0;
} 
