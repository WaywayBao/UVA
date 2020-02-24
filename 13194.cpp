//uva 13194
#include<iostream>
#include<cmath>
#include<vector>
#define limit 1000005
using namespace std;

vector<int> table;
int not_prime[limit] = {true, true};

void init(){    //create prime table
    for(int i = 2; i < limit; ++i){
           if(!not_prime[i]){
             for (int k = i; k<limit; k += i)
                 not_prime[k] = true;
             table.push_back(i);
           }
    }
}

long long series(int i, int n){  //grometeic seriesšæ•¸
     return (pow(i, n+1) - 1)/(i - 1);
}

int main(){
     init();
     int T;
     cin >> T;
     while(T--){
            long long ans = 1, N, value;
            cin >> N;
            value = N;
            for(int i =0; i<table.size()&&table[i]*table[i]<=value; ++i){
                int cnt = 0;
                if(value%table[i] != 0) continue;
                while(value%table[i] == 0){
                     ++cnt;
                     value /= table[i];
                }
              ans *= series(table[i], cnt);
             //cout<<ans<<" "<<value<<endl;
            }
         if(value != 1) ans = ans*(value+1) - N;
         else ans -= N;
         if(ans == N) cout << "perfect" << endl;
         else if(ans < N) cout << "deficient" << endl;
         else cout << "abundant" << endl;
      }
      return 0;
}
