#include "common_header.hh"
using namespace std;


double myPowHelper(double x, int n){
    if(n==1){
        return x;
    }else {
        return x * myPowHelper(x, n-1);        
    }
}

double myPow(double x, int n) {
    if(n < 0){
        x =  1 / x ;
        n = -1 * n ;
    }
    double ans = myPowHelper(x, n);
    return ans ;
}

void test_myPow(){
    double num = 2 ;
    int n = 3 ; 
    double ans = myPow(num, n);
    cout<<"Answer = "<<ans<<endl;
}