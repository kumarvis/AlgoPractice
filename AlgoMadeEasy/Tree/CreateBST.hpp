#ifndef CREATE_BST_HH
#define CREATE_BST_HH

#include<iostream>
#include <vector>

using namespace std ;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void printPostOrder(struct Node *root){
    if(root){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->data<<"\t";
    }
}

void printPreorder(struct Node *root){
    if(root){
        cout<<root->data<<"\t";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printInorder(struct Node *root){
    if(root){
        printInorder(root->left);
        cout<<root->data<<"\t";
        printInorder(root->right);
    }
}

void printReverseInorder(struct Node *root){
    if(root){
        printReverseInorder(root->right);
        cout<<root->data<<"\t";
        printReverseInorder(root->left);
    }
}

struct Node* insertNode(struct Node *root, int data){
    if(root ==  NULL){
        struct Node *tmp = new Node();
        tmp->data = data;
        tmp->left = NULL ;
        tmp->right = NULL ; 
        return tmp ;
    }else {
        if(data < root->data){
            root->left = insertNode(root->left, data);
        }else{
            root->right = insertNode(root->right, data);
        }   
    }
    return root ;
}

void run_createBST(){
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45};
    struct Node *BST = NULL ;
    for (int item : vec_arr){
        BST = insertNode(BST, item);
    }
    cout<<"Print Inorder for Check"<<endl;
    printInorder(BST);
    cout<<endl;

}

#endif //CREATE_BST_HH