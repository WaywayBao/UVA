#include<iostream>		//uva288 
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#define N 4000
using namespace std;
typedef string BigInteger;

BigInteger add(BigInteger a,BigInteger b);
BigInteger sub(BigInteger a,BigInteger b);
BigInteger mul(BigInteger a,BigInteger b);
BigInteger pow(BigInteger a,BigInteger b);

bool compare(const string &a,const string &b){
	if(a.size()>b.size()) return true;
	else if(a.size()<b.size()) return false;
	int i=a.size()-1;
		while(i>=0&&a[i]==b[i]) --i;
	if(i==-1)	return true;
	else	return a[i]>b[i];
}

int main() {
	string str,number;
	while(cin>>str){
		int precedence=0;
		vector<string> v1;
		vector<int> sign;
		for(int i=0,start=0,cnt=0;i<=str.size();++i,++cnt){
			if(i==str.size()||!isdigit(str[i])){
				number=str.substr(start,cnt);
				reverse(number.begin(),number.end());
				v1.push_back(number);
				if(i!=str.size()){		//(0,+) (1,-) (2,*) (3,**)
					if(str[i]=='+')
						precedence=0;
					else if(str[i]=='-')
						precedence=1;
					else if(str[i]=='*'){
						if(str[i+1]=='*'){
							precedence=3;
							i++;
						}
						else
							precedence=2;
					}
				}else 
					precedence=0;
				while(sign.size()>0&&precedence<sign.back()&&sign.back()>1){		//mul and pow
					if(sign.back()==2)
						v1[v1.size()-2]=mul(v1[v1.size()-1],v1[v1.size()-2]);
					else if(sign.back()==3)
						v1[v1.size()-2]=pow(v1[v1.size()-2],v1[v1.size()-1]);
					v1.pop_back();
					sign.pop_back();
				}
				if(i!=str.size())
					sign.push_back(precedence);
				start=i+1;
				cnt=-1;
			}
		}
		BigInteger sum=v1[0];
		for(int i=1;i<v1.size();++i){	//add and sub
			if(sign[i-1]==0)
				sum=add(sum,v1[i]);
			else if(sign[i-1]==1)
				sum=sub(sum,v1[i]);		
		}
		reverse(sum.begin(),sum.end());
		cout<<sum<<endl;		//output answer
	}
	return 0;
}

BigInteger mul(BigInteger a,BigInteger b){
	if(a=="0"||b=="0")	return "0";
	int temp[N]={0};
	BigInteger sum="\0";		//ASCII '0'=48
	sum.resize(N);
	for(int i=0;i<b.size();i++)
		for(int j=0;j<a.size();j++)
			temp[j+i]+=(a[j]-48)*(b[i]-48);
	for(int i=0,carry=0;i<N;i++){
		temp[i]+=carry;
		carry=temp[i]/10;
		temp[i]%=10;
		sum[i]=temp[i]+48;
	}
	int i=N;
	while(--i>0&&(sum[i]=='\0'||sum[i]=='0'));
	sum.resize(i+1);
	return sum;
}

BigInteger pow(BigInteger a,BigInteger b){
	if(b=="0") return "1";
	else if(b=="1") return a;
	int cnt=0;
	for(int i=0,k=1;i<b.size();++i,k*=10)
		cnt+=(b[i]-48)*k;
	BigInteger temp=a;
	int i=1;
	for(i=1;i*2<=cnt;i*=2)
		a=mul(a,a);
	while(i<cnt){
		a=mul(a,temp);
		++i;
	}
	return a;
}

BigInteger sub(BigInteger a,BigInteger b){
	if(a.compare(b)==0)	return "0";
	else if(a=="0")	return b+"-";
	else if(b=="0")	return a;
	if (a[a.size()-1]=='-'){
		a.resize(a.size()-1);
		return add(a,b)+"-";
	}
	bool sign=false;
	if(compare(b,a)){
		BigInteger str=a;
		a=b;
		b=str;
		sign=true;
	}
	BigInteger sum="\0";
	sum.resize(N);
	int temp[N]={0};
	int i=0,carry=0;
	for(i=0;i<a.size();++i)
		temp[i]=a[i]-48;
	for(i=0;i<b.size();++i){
		temp[i]-=(b[i]-48)+carry;
		carry=(temp[i]<0);
		if(temp[i]<0)
			temp[i]+=10;
	}
	while(carry!=0){
		temp[i]-=carry;
		carry=(temp[i]<0);
		if(temp[i]<0)
			temp[i]+=10;
		i++;
	}
	for(i=0;i<a.size();++i)
		sum[i]=temp[i]+48;
	i=N;
	while(--i>0&&(sum[i]=='\0'||sum[i]=='0'));
	if(sign)
		sum[++i]='-';
	sum.resize(i+1);
	return sum;
}

BigInteger add(BigInteger a,BigInteger b){
	if(a=="0") return b;
	else if(b=="0") return a;
	if(a[a.size()-1]=='-'){ 
		a.resize(a.size()-1);
		return sub(b,a);
	} 
	int temp[N]={0};
	BigInteger sum="";
	sum.resize(N);
	for(int i=0;i<a.size();++i)
		temp[i]=a[i]-48;
	for(int i=0;i<b.size();++i)
		temp[i]+=b[i]-48;
	for(int i=0,carry=0;i<N;i++){
		temp[i]+=carry;
		carry=temp[i]/10;
		temp[i]%=10;
		sum[i]=temp[i]+48;
	}
	int i=N;
	while(--i>0&&(sum[i]=='\0'||sum[i]=='0'));
	sum.resize(i+1);
	return sum;
}
