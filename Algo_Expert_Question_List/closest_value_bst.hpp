#include<iostream>
#include<vector>
#include "BST.hpp"

using namespace std ;

int fun_closest_value_bst(){
    return 0;
}


void run_closest_value_bst(){
    int arr[] = {3, 5, -4, 8, 11, 1, -1, 6};
    int N = sizeof(arr)/ sizeof(arr[0]);
    int S = 10 ;
    vector<int> vec_arr(arr, arr+N) ;
    BST_Node *ROOT = create_bst_from_vector(vec_arr);
    inorder(ROOT);
    cout<<"run_closest_value_bst exit"<<endl;
}