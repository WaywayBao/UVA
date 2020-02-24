#include<iostream>
#include<string>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
	    string str;
        cin >> str;
        int len = str.length(), cnt = 0;
        int front[30] = {};
		int back[30] = {};
        for(int i=0; i<30; ++i) front[i] = 999999, back[i] = -1;
        for(int i=0, j=len-1; i<len; ++i, --j){
            if(front[str[i]-'A'] == 999999) front[str[i]-'A'] = i;
            if(back[str[j]-'A'] == -1) back[str[j]-'A'] = j;
        }
        for(int i=0; i<26; ++i){
            if(front[i] != 999999){
            	int flag1 = front[i];
                for(int j=0; j<26; ++j){
                	if(back[j] <= flag1) continue;
                    int flag2 = 0;
                    for(flag2 = flag1+1; flag2 < len; ++flag2){
			    	    if(str[flag2] == (j+'A')) break;
				    }
                    if(flag2 != len){
                        for(int k=0; k<26; ++k)
			               	if(back[k] > flag2) ++cnt;
                	}
                }
            }
        }
        cout<< cnt <<endl;
    }
    return 0;
}
