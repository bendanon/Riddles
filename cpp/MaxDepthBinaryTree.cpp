#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a binary tree, find its maximum depth.
The maximum depth of a binary tree is the number of nodes 
along the longest path from the root node down to the farthest leaf node.
*/ 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int _preorder(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    return std::max(1 + _preorder(root->left), 1 + _preorder(root->right));
}

int solution(TreeNode* A){
    return _preorder(A);
}

TEST(MaxDepthSuite, trivial_0)
{
    ASSERT_EQ(0, solution(nullptr));
}

TEST(MaxDepthSuite, trivial_1)
{
    array<TreeNode, 1> nodes {1};

    ASSERT_EQ(1, solution(&nodes[0]));
}

TEST(MaxDepthSuite, full) { 
    array<TreeNode, 7> nodes {1, 2, 3, 4, 5, 6, 7};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];

    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];

    ASSERT_EQ(3, solution(&nodes[0]));
}

TEST(MaxDepthSuite, example)
{
    array<TreeNode, 2> nodes {1, 2};

    nodes[0].left = &nodes[1];

    ASSERT_EQ(2, solution(&nodes[0]));
}

TEST(MaxDepthSuite, right_leaves) { 
    array<TreeNode, 5> nodes {1, 2, 2, 3, 3};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].right = &nodes[3];
    nodes[2].right = &nodes[4];
    ASSERT_EQ(3, solution(&nodes[0]));

}
    
TEST(MaxDepthSuite, triangle) { 
    array<TreeNode, 5> nodes {1, 2, 3, 4, 5};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[2].right = &nodes[4];
    
    ASSERT_EQ(3, solution(&nodes[0]));

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}