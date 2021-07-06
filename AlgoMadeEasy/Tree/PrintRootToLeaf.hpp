#ifndef PRINT_ROOT_LEAF
#define PRINT_ROOT_LEAF

#include <iostream>
#include <stack>
#include <limits>
#include "CreateBST.hpp"
#include <math.h>
#include <vector>
using namespace std;

void printVector(vector<int> vec_arr){
    for(auto i : vec_arr)
        cout<<i<<" ";
    cout<<endl;
}

void printRoot2LeafPath(struct Node *root, vector<int> vec_arr){
    if(root==NULL)
        return ;
    vec_arr.push_back(root->data);
    if(root->left == NULL && root->right == NULL )
        printVector(vec_arr);
    else{
        printRoot2LeafPath(root->left, vec_arr);
        printRoot2LeafPath(root->right, vec_arr);
    }
}

void run_PrintRootToLeaf(){
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45};
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
    vector<int> vec_print_arr;
    printRoot2LeafPath(root, vec_print_arr);

}
#endif 