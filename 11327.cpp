#include<iostream>		//uva 11327 Enumerating Rational Numbers
using namespace std; 
int prime[50000];
bool _isNotPrime[200001]={true,true};
int coprime[200001]={0,2};
long long K[200001]={0,2};

void Generate_Prime(){
	for(int i=2,cnt=0;i<=200000;++i){
		if(!_isNotPrime[i]){
			for(int j=i*2;j<=200000;j+=i)
				if(!_isNotPrime[j]) _isNotPrime[j]=true;
			prime[cnt++]=i;
			coprime[i]=i-1;
		}
		else{
			coprime[i]=i;
			for(int j=0;prime[j]*2<=i;++j)
				if(i%prime[j]==0)
					coprime[i]-=coprime[i]/prime[j];	//coprime[i]=coprime[i]/prime[j]*(prime[j]-1);	n*(1-1/q1)*(1-1/q2)*(1-1/q3)...
		}
		K[i]=K[i-1]+coprime[i];
	}
}

int main(){
	long long k;
	Generate_Prime();
	while(cin>>k&&k){
		if(k==1)
			cout<<"0/1"<<endl;
		else if(k==2)
			cout<<"1/1"<<endl;
		else{
			int left=1,right=200000,mid;
			while(left<right){		//Binary search
				mid=(left+right)/2;
				if(K[mid]<k)		//K[1]=2,K[2]=3,K[3]=5,K[4]=7 ... 
					left=mid+1;
				else{
					right=mid;
					if(K[mid]==k)
						break;
				}
			}
			// ¤À¤l/right
			int a,b,temp,cnt=k-K[right-1],i=0;
			while(cnt){
				++i;
				a=right,b=i;
				while(a%b!=0){		//GCD
					temp=b;
					b=a%b;
					a=temp;
				}
				if(b==1)
					--cnt;
			//cout<<"hihi : "<<cnt<<endl;
			}
			cout<<i<<"/"<<right<<endl;
		}
	}
	return 0;
}

