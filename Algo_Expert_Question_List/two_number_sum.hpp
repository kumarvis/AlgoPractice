#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std ;

void fun_two_number_sum(vector<int> &vec_arr, int Sum){
    unordered_set<int> my_set ;
    for(int ii=0 ; ii < vec_arr.size() ; ii++){
        int tmp = Sum - vec_arr[ii];
        if(my_set.find(tmp) == my_set.end()){
            my_set.insert(vec_arr[ii]);
        }else{
            cout<<"Find the match"<<endl;
            cout<<"Pair"<<vec_arr[ii]<<" "<<tmp<<endl;
        }
    }
}

void run_two_number_sum(){
    int arr[] = {3, 5, -4, 8, 11, 1, -1, 6};
    int N = sizeof(arr)/ sizeof(arr[0]);
    int S = 10 ;
    vector<int> vec_arr(arr, arr+N) ;
    fun_two_number_sum(vec_arr, S);
    
}