#ifndef FIND_WIDTH
#define FIND_WIDTH

#include<iostream>
#include<stack>
#include<limits>
#include <queue>
#include "CreateBST.hpp"
using namespace std;

int getWidthBinaryTree(struct Node *root){
    if(root == NULL)
        return 0;
    queue<Node *> node_queue;
    node_queue.push(root);
    int curr_node_cnt = node_queue.size();
    int max_count = curr_node_cnt;

    while(!node_queue.empty()){
        int tmp_max = 0;
        while(curr_node_cnt--){
            struct Node *tmp = node_queue.front();
            if(tmp->left){  
                node_queue.push(tmp->left);
                tmp_max++;
            }
            if(tmp->right){
                node_queue.push(tmp->right);
                tmp_max++;
            }
            node_queue.pop();
        }
        curr_node_cnt = node_queue.size();
        if(tmp_max > max_count)
            max_count = tmp_max;
    }
    
    return max_count;
}

void run_getWidthBinaryTree(){
    vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
    int ans = getWidthBinaryTree(root);
    cout<<"Width of Binary Tree = "<<ans;
}

#endif 