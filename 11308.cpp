#include<iostream>		//uva 11308
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct MyRecipe{
	MyRecipe(string name,int totalPrice){
		this->name=name;
		this->totalPrice=totalPrice;
	}
	string name;
	int totalPrice;
};
bool compare(const MyRecipe& a,const MyRecipe& b){
	if(a.totalPrice==b.totalPrice)
		return	a.name<=b.name;
	return	a.totalPrice<=b.totalPrice;
}
int main(){
	int testcase,m,n,b,k,price,x,totalPrice;
	string binder,ingred,name,requirement;
	cin>>testcase;
	while(testcase--){
		getchar();
		getline(cin,binder);
		for(int i=0;i<binder.size();i++)
			binder[i]=toupper(binder[i]);
		cin>>m>>n>>b;
		map<string,int> ingredient;
		while(m--){
			cin>>ingred>>price;
			ingredient[ingred]=price;
		}
		vector<MyRecipe> v;
		while(n--){
			getchar();
			getline(cin,name);
			cin>>k;
			totalPrice=0;			
			while(k--){
				cin>>requirement>>x;
				totalPrice+=ingredient[requirement]*x;	
			}
			MyRecipe r(name,totalPrice);
			v.push_back(r);
		}
		sort(v.begin(),v.end(),compare);
		cout<<binder<<endl;
		vector<MyRecipe>::iterator it=v.begin();
		for(;it!=v.end()&&(*it).totalPrice<=b;it++)
			cout<<(*it).name<<endl;
		if(it==v.begin())
			cout<<"Too expensive!"<<endl;			
		cout<<endl;			
	}
	return 0;
}
