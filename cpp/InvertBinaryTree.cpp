#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a binary tree, invert the binary tree and return it.
Invert means left child becomes right child and vice versa
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


void _solution(TreeNode* A){
    if(A == nullptr){
        return;
    }
    std::swap(A->left, A->right);
    _solution(A->left);
    _solution(A->right);
}

TreeNode* solution(TreeNode* A){
    _solution(A);
    return A;
}

TEST(MaxDepthSuite, trivial_0)
{
    ASSERT_EQ(nullptr, solution(nullptr));
}

TEST(MaxDepthSuite, trivial_1)
{
    array<TreeNode, 1> nodes {1};
    ASSERT_TRUE(compare_tree_by_val(&nodes[0], solution(&nodes[0])));
}

TEST(MaxDepthSuite, example) { 
    array<TreeNode, 7> nodes {1, 2, 3, 4, 5, 6, 7};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];

    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];

    array<TreeNode, 7> exp {1, 2, 3, 4, 5, 6, 7};

    exp[0].left = &exp[2];
    exp[0].right = &exp[1];

    exp[2].left = &exp[6];
    exp[2].right = &exp[5];

    exp[1].left = &exp[4];
    exp[1].right = &exp[3];

    ASSERT_TRUE(compare_tree_by_val(&exp[0], solution(&nodes[0])));
}

TEST(MaxDepthSuite, right_leaves) { 
    array<TreeNode, 5> nodes {1, 2, 2, 3, 3};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].right = &nodes[3];
    nodes[2].right = &nodes[4];

    array<TreeNode, 5> exp {1, 2, 2, 3, 3};

    exp[0].left = &exp[2];
    exp[0].right = &exp[1];

    exp[2].left = &nodes[4];
    exp[1].left = &nodes[3];

    ASSERT_TRUE(compare_tree_by_val(&exp[0], solution(&nodes[0])));
}
    
TEST(MaxDepthSuite, triangle) { 
    array<TreeNode, 5> nodes {1, 2, 3, 4, 5};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[2].right = &nodes[4];

    array<TreeNode, 5> exp {1, 2, 3, 4, 5};

    exp[0].left = &exp[2];
    exp[0].right = &exp[1];

    exp[2].left = &exp[4];
    exp[1].right = &exp[3];

    ASSERT_TRUE(compare_tree_by_val(&exp[0], solution(&nodes[0])));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}