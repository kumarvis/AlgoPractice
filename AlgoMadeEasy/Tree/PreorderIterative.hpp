#ifndef PREORDER_ITR_HPP
#define PREORDER_ITR_HPP

#include<iostream>
#include<stack>
#include "CreateBST.hpp"

using namespace std;

void preorderIterative(struct Node *root) {
	stack<struct Node*> node_stk;
	struct Node* curr = root;

	while(true){
        while(curr){
            cout << curr->data << "\t";
            node_stk.push(curr);
            curr = curr->left;
        }
        if(node_stk.empty()){
            break;
        }
        curr = node_stk.top()->right;
        node_stk.pop();
    }
}
	
void run_preorderIterative() {
	vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printPreorder(root);
	cout << endl;
	preorderIterative(root);
	cout << endl;
}

#endif // !PREORDER_ITR_HPP
