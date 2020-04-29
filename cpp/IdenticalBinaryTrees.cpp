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


TEST(UniqueBstSuite, Example) { 
    array<TreeNode, 5> ones {1, 1, 1, 1, 1};
    array<TreeNode, 5> twos {2, 2, 2, 2, 2};
    array<TreeNode, 5> threes {3, 3, 3, 3, 3};

    ones[0].right = &threes[0];
    threes[0].left = &twos[0];

    ones[1].right = &twos[1];
    twos[1].right = &threes[1];

    twos[2].left = &ones[2];
    twos[2].right = &threes[2];

    threes[3].left = &ones[3];
    ones[3].right = &twos[3];
    
    threes[4].left = &twos[4];
    twos[4].left = &ones[4];

    vector<TreeNode*> expected { &ones[0], &ones[1], &twos[2], &threes[3], &threes[4] };
    vector<TreeNode*> ans = solution(3);

    remove(begin(ans), end(ans), nullptr);

    ASSERT_EQ(expected.size(), ans.size());
    ASSERT_TRUE(is_permutation(begin(expected), end(expected), begin(ans), compare_tree_by_val));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}