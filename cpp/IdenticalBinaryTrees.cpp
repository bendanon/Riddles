#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/ 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare_tree_by_val(TreeNode* a, TreeNode* b){
    if(a == NULL && b == NULL){
        return true;
    }
    if(a == NULL && b != NULL || a != NULL && b == NULL){
        return false;
    }

    return a->val == b->val && 
           compare_tree_by_val(a->right, b->right) && 
           compare_tree_by_val(a->left, b->left);
}

int solution(TreeNode* a, TreeNode* b){
    return compare_tree_by_val(a, b) ? 1 : 0;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}