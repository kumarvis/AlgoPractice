#ifndef BST_UTILS_HH
#define BST_UTILS_HH

#include<iostream>
#include<vector>
using namespace std ;

struct BST_Node{
    int value;
    BST_Node *left ;
    BST_Node *right ;
};

void insert_node(BST_Node *&BST, int val){

}

BST_Node* create_bst_from_vector(vector<int> vec_arr){
    BST_Node *bst = NULL ;
    for(int ii=0 ; ii < vec_arr.size(); ii++){
        
    }
    return bst ;
}
#endif