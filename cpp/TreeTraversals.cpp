#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes’ values.
*/ 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void _preorder(TreeNode* root, vector<int>& ret){
    if(root == nullptr){
        return;
    }
    ret.push_back(root->val);
    _preorder(root->left, ret);
    _preorder(root->right, ret);
}

vector<int> preorderTraversal(TreeNode* A) {
    vector<int> ret;
    _preorder(A, ret);
    return ret;
}

void _postorder(TreeNode* root, vector<int>& ret){
    if(root == nullptr){
        return;
    }
    _postorder(root->left, ret);
    _postorder(root->right, ret);
    ret.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* A) {
    vector<int> ret;
    _postorder(A, ret);
    return ret;
}

void _inorder(TreeNode* root, vector<int>& ret){
    if(root == nullptr){
        return;
    }

    _inorder(root->left, ret);
    ret.push_back(root->val);
    _inorder(root->right, ret);
}

vector<int> inorderTraversal(TreeNode* A) {
    vector<int> ret;
    _inorder(A, ret);
    return ret;
}


TEST(SymmetricTreeSuite, full) { 
    array<TreeNode, 7> nodes {1, 2, 3, 4, 5, 6, 7};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];

    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];

    vector<int> expected_pre {1, 2, 4, 5, 3, 6, 7};
    ASSERT_EQ(expected_pre, preorderTraversal(&nodes[0]));
    
    vector<int> expected_post {4, 5, 2, 6, 7, 3, 1};
    ASSERT_EQ(expected_post, postorderTraversal(&nodes[0]));

    vector<int> expected_in {4, 2, 5, 1, 6, 3, 7};
    ASSERT_EQ(expected_in, inorderTraversal(&nodes[0]));


}

TEST(TraversalsSuite, example)
{
    array<TreeNode, 3> nodes {1, 2, 3};

    nodes[0].right = &nodes[1];
    nodes[1].left = &nodes[2];

    vector<int> expected_pre {1, 2, 3};
    ASSERT_EQ(expected_pre, preorderTraversal(&nodes[0]));
    
    vector<int> expected_post {3, 2, 1};
    ASSERT_EQ(expected_post, postorderTraversal(&nodes[0]));

    vector<int> expected_in {1, 3, 2};
    ASSERT_EQ(expected_in, inorderTraversal(&nodes[0]));
}

TEST(TraversalsSuite, right_leaves) { 
    array<TreeNode, 5> nodes {1, 2, 2, 3, 3};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].right = &nodes[3];
    nodes[2].right = &nodes[4];
    
    vector<int> expected_pre {1, 2, 3, 2, 3};
    ASSERT_EQ(expected_pre, preorderTraversal(&nodes[0]));
    
    vector<int> expected_post {3, 2, 3, 2, 1};
    ASSERT_EQ(expected_post, postorderTraversal(&nodes[0]));

    vector<int> expected_in {2, 3, 1, 2, 3};
    ASSERT_EQ(expected_in, inorderTraversal(&nodes[0]));
}

TEST(TraversalsSuite, triangle) { 
    array<TreeNode, 5> nodes {1, 2, 3, 4, 5};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[2].right = &nodes[4];
    
    vector<int> expected_pre {1, 2, 4, 3, 5};
    ASSERT_EQ(expected_pre, preorderTraversal(&nodes[0]));

    vector<int> expected_post {4, 2, 5, 3, 1};
    ASSERT_EQ(expected_post, postorderTraversal(&nodes[0]));

    vector<int> expected_in {4, 2, 1, 3, 5};
    ASSERT_EQ(expected_in, inorderTraversal(&nodes[0]));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}