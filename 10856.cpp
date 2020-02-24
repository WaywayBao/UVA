#include <iostream>		//uva 10856 Recover Factorial
using namespace std;

static const int INIT_FACTOR_COUNT = 2703664;
static const int MAX_TOTAL_FACTOR_COUNT = 10000010;
static const int FACTOR = 1700;
static int factorial[INIT_FACTOR_COUNT];
static int ans[MAX_TOTAL_FACTOR_COUNT];
bool factor[FACTOR];
int prime[450];

int main(){
    int cnt = 0, cas = 0, N;
    for(int n = 2; n<FACTOR; ++n){		//create prime table
        if(!factor[n]){
            for(int np=(n+n); np<FACTOR; np+=n) factor[np] = true;
            prime[cnt]=n;
            cnt++;
        }
    }  
  
    for(int n = 2; n<INIT_FACTOR_COUNT;++n){
        int j=0;
        while(prime[j]*prime[j]<=n){
            if(n%prime[j]==0)
            	break;
            ++j;
        }
        //calculate prime factor number of n!
		if(prime[j]*prime[j]>n)		//when n is prime
    	    factorial[n] = factorial[n-1]+1;
        else
	        factorial[n] = factorial[n-1] + factorial[n/prime[j]]-factorial[n/prime[j]-1]+1;		//(n-1)! + minimal prime factor+ (n/factor)!-(n/factor-1)!
        ans[factorial[n]] = n;
    }
    
    while(cin >> N && N >= 0 ){
        if( !N || ans[N])
            cout << "Case " << ++cas << ": " << ans[N] << "!" << endl;
        else
            cout << "Case " << ++cas << ": Not possible." << endl;
    }
    return 0;
}


//Binary search
// 
//#include <iostream>		//uva 10856 Recover Factorial
//using namespace std;
//
//static const int INIT_FACTOR_COUNT = 2703664;
//static const int FACTOR = 1700;
//static int factorial[INIT_FACTOR_COUNT];
//bool factor[FACTOR];
//int prime[450];
//
//int main(){
//    int cnt = 0, cas = 0, N;
//    for(int n = 2; n<FACTOR; ++n){		//create prime table
//        if(!factor[n]){
//            for(int np=(n+n); np<FACTOR; np+=n) factor[np] = true;
//            prime[cnt]=n;
//            cnt++;
//        }
//    }    
//    for(int n = 2; n<INIT_FACTOR_COUNT;++n){
//        int j=0;
//        while(prime[j]*prime[j]<=n){
//            if(n%prime[j]==0)
//            	break;
//            ++j;
//        }
//        //calculate prime factor number of n!
//		if(prime[j]*prime[j]>n)		//when n is prime
//    	    factorial[n] = factorial[n-1]+1;
//        else
//	        factorial[n] = factorial[n-1] + factorial[n/prime[j]]-factorial[n/prime[j]-1]+1;		//(n-1)! + minimal prime factor+ (n/factor)!-(n/factor-1)!
//    }
//    while(cin >> N && N >= 0 ){
//		int right= INIT_FACTOR_COUNT-1,left=0,mid;
//    	while(left<right){
//    		mid=(left+right)/2;
//			/*if(N==factorial[mid])
//				break;
//    		else */if(N<=factorial[mid])
//				right=mid;
//    		else if(N > factorial[mid])
//				left=mid+1;
//		}
//		if(N==factorial[right])
//		    cout << "Case " << ++cas << ": " << right << "!" << endl;
//		else
//            cout << "Case " << ++cas << ": Not possible." << endl;
//    }
//    return 0;
//}
