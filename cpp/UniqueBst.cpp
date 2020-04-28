#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.
1 <= A <= 15
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

vector<TreeNode*> _solution(int start, int end){

    vector<TreeNode*> ret;

    if(start > end){
        ret.push_back(nullptr);
        return ret;
    }

    for(int root = start; root <= end; ++root){

        vector<TreeNode*> left_subtrees = _solution(start, root - 1);
        vector<TreeNode*> right_subtrees = _solution(root + 1, end);

        for(auto ls : left_subtrees){

            for(auto rs : right_subtrees){
                
                TreeNode* root_node = new TreeNode(root);
                root_node->left = ls;
                root_node->right = rs;
                ret.push_back(root_node);
            }
        }
    }

    return ret;
}

vector<TreeNode*> solution(int n){
    return _solution(1, n);
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