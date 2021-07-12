#ifndef KTH_SMALLEST_ELM
#define KTH_SMALLEST_ELM

#include <iostream>
#include <stack>
#include <limits>
#include <string>
#include "CreateBST.hpp"

void run_kthSmallestElment(struct Node *root, int k, int & ans){
    if(root==NULL)
        return;
    static int count = 0;
    run_kthSmallestElment(root->left, k, ans);
    if(++count == k){
        ans = root->data;
        return ;
    }
    run_kthSmallestElment(root->right, k, ans);
}   

void run_kthSmallestElment() {
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);
    int ans = 0 ; 
    int k = 5 ;
    run_kthSmallestElment(root, k, ans);
    cout<<endl;
    cout<<k<<" kth Smallest Elements = "<<ans;
}

#endif 
