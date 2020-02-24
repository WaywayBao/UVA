#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	while(cin>>N&&N){
		for(int j=1;j<300;j++){
			vector<int> v;
			for(int k=0;k<=N;k++)
				v.push_back(k);
			int currentindex=0,count;
			v.erase(v.begin()+1);
			while(v.size()>1){
				count=0;
				while(count<j){
					currentindex++;
					if(v.begin()+currentindex==v.end())
						currentindex=1;
					count++;
				}
				if(v[currentindex]==13)
					break;
				v.erase(v.begin()+currentindex);			
				currentindex--;
			}
			if(v.size()==2){
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
 


/*#include <iostream>
#define M 13
using namespace std;

int josephus(int n, int k) {
	int s = 0;
	for (int i = 2; i <= n; i++)
		s = (s + k) % i;
	return s;
}

int main(){
	int n;
	cout<<josephus(12,3)<<endl;
	while ( cin >> n && n ) {
		for ( int i = 1 ; i < n ; ++ i ) {
			int k = 0;
			for ( int j = 2 ; j <= n-1 ; ++ j )
				k = (k+i)%j;
//			if ( k == M-2 ) {
			cout<<i<<" "<<k<<endl;
//				break;
//			}
		}
	}
	return 0;
}*/ 
