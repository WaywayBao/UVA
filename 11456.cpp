#include <iostream>
int LIS[2001], LDS[2001], train[2001];

using namespace std;
int main() {
	int m, n;
	cin >> m;
	while(m--){
		cin >> n;
		for(int i=n-1; i>=0; --i)
			cin >> train[i];
		for(int i=0; i<=n; ++i){
			LIS[i] = LDS[i] = 1;    //initial
			for(int j=0; j<i; ++j){
			  	if (train[i] > train[j])
		    		LIS[i] = max(LIS[i], LIS[j]+1);
		    	if (train[i] < train[j])
		    		LDS[i] = max(LDS[i], LDS[j]+1);
	  		}
		}
		int MAX = 0;
		for(int i=0; i<n; ++i)
			if (MAX < LIS[i]+LDS[i]-1)	MAX = LIS[i]+LDS[i]-1;
		cout << MAX <<endl;
	}
	return 0;
}
