#include<iostream>
#include<vector>
using namespace std ;

void fun_two_number_sum(vector<int> &vec_arr, int Sum){
    
}

void run_two_number_sum(){
    int arr[] = {3, 5, -4, 8, 11, 1, -1, 6};
    int N = sizeof(arr)/ sizeof(arr[0]);
    int S = 10 ;
    vector<int> vec_arr(arr, arr+N) ;
    fun_two_number_sum(vec_arr, S);
    
}