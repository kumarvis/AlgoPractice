#ifndef SORTED_ARR_BST
#define SORTED_ARR_BST

#include<iostream>
#include<stack>
#include <limits>
#include<string>
#include "CreateBST.hpp"

struct Node * sortedArrToBST(vector<int> vec_arr, int st_index, int end_index){
    if(st_index > end_index)
        return NULL ;
    int mid_index = (st_index + end_index) / 2 ;
    int data = vec_arr[mid_index];
    struct Node *root = new Node();
    root->data = data;
    root->left = sortedArrToBST(vec_arr, st_index, mid_index-1);
    root->right = sortedArrToBST(vec_arr, mid_index + 1, end_index);
    return root;
}

void run_sortedArrToBST(){
    vector<int> vec_arr = {2, 4, 8, 10, 12};
	struct Node* BST = NULL;
    BST = sortedArrToBST(vec_arr, 0 , vec_arr.size()-1);
    cout<<"Print Inorder for Check"<<endl;
    printInorder(BST);
}

#endif 