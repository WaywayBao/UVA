#include<iostream>
#include<cstring>
#define N 26
#define MAX 100005
using namespace std;

int dp[MAX][N];
int len, cnt;

//solved by recursive
//void search(int index, int rec){
//	for(int i=0; i<N; ++i){
//		if(dp[index][i] < len){
//			if(rec == 2) ++cnt;
//			else search(dp[index][i]+1, rec+1);
//		}
//	}
//}

int main(){
    int T;
    string str;
    cin >> T;
    while(T--){
        cin >> str;
        len = str.length(), cnt = 0;

		for(int i=0; i<N; ++i)
			dp[len][i] = len;
        for(int i=len-1; i>=0; --i){
			memcpy(dp[i], dp[i+1], sizeof(dp[0]));
			dp[i][str[i]-'A'] = i;
        }
        for(int i=0; i<N; ++i){
			if(dp[0][i] < len){
				int x = dp[0][i] + 1;
				for(int j=0; j<N; ++j){
					if(dp[x][j] < len){
						int y = dp[x][j] + 1;
						for(int k=0; k<N; ++k)
							if(dp[y][k] < len)	++cnt;
					}
				}
			}
		}
        //search(0,0);
        cout<< cnt <<endl;
    }
    return 0;
}
