#include<iostream>		//uva1207
#include<string>
#define min(x, y) ((x)<(y)?(x):(y))
using namespace std;

int main() {
	string str1, str2;
	int dp[510][510]={0},len1,len2;
    for(int i = 1; i < 510; i++){ 
        dp[i][0] = i;
        dp[0][i] = i;
	}
	while(cin>>len1){
		cin>>str1>>len2>>str2;
        for(int i=1;i<=len1;i++) {
       		for(int j=1;j <=len2;j++) {
            	if(str1[i-1] == str2[j-1])
            	    dp[i][j] = dp[i-1][j-1];
            	else
            	    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
       		}
	    }
    	cout<<dp[len1][len2]<<endl;
	}
    return 0;
}
