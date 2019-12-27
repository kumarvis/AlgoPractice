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

void inorder(BST_Node *root){
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

void insert_node(BST_Node*& BST, int val){
    if(BST == NULL){
        BST_Node *tmp = new BST_Node();
        tmp->value = val;
        tmp->left = NULL;
        tmp->right = NULL ;
        BST = tmp;
    }else{
        if(BST->value > val){
            insert_node(BST->left, val);
        }else{
            insert_node(BST->right, val);
        }
    }

}

BST_Node* create_bst_from_vector(vector<int> vec_arr){
    BST_Node *bst = NULL ;
    for(int ii=0 ; ii < vec_arr.size(); ii++){
        insert_node(bst, vec_arr[ii]);
    }
    return bst ;
}
#endif