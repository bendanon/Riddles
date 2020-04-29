#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
*/ 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool _solution(TreeNode* a, TreeNode* b){

    if(a == nullptr && b == nullptr){
        return true;
    }

    return (a && b && a->val == b->val) &&
            _solution(a->left, b->right) &&
            _solution(a->right, b->left);

}

int solution(TreeNode* A){
    return _solution(A, A)? 1 : 0;
}

TEST(SymmetricTreeSuite, Example_positive) { 
    array<TreeNode, 7> nodes {1, 2, 2, 3, 4, 4, 3};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];

    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];

    ASSERT_EQ(1, solution(&nodes[0]));
}

TEST(SymmetricTreeSuite, Example_negative) { 
    array<TreeNode, 5> nodes {1, 2, 2, 3, 3};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].right = &nodes[3];
    nodes[2].right = &nodes[4];

    ASSERT_EQ(0, solution(&nodes[0]));
}

TEST(SymmetricTreeSuite, triangle_positive) { 
    array<TreeNode, 5> nodes {1, 2, 2, 3, 3};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[2].right = &nodes[4];

    ASSERT_EQ(1, solution(&nodes[0]));
}

TEST(SymmetricTreeSuite, val_diff) { 
    array<TreeNode, 5> nodes {1, 2, 2, 3, 4};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = &nodes[3];
    nodes[2].right = &nodes[4];

    ASSERT_EQ(0, solution(&nodes[0]));
}

//9 1 1 1 -1 -1 -1 1 -1 -1

TEST(SymmetricTreeSuite, struct_diff) { 
    array<TreeNode, 4> nodes {1, 1, 1, 1};

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];

    nodes[1].left = nullptr;
    nodes[1].right = nullptr;

    nodes[2].left = nullptr;
    nodes[2].right = &nodes[3];

    nodes[3].left = nullptr;
    nodes[3].right = nullptr;

    ASSERT_EQ(0, solution(&nodes[0]));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}