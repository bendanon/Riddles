#include <gtest/gtest.h>
 
/*
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a
binary tree in which the depth of the two subtrees of every node never 
differ by more than 1. 
*/

//Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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

int split_list(ListNode* start, ListNode* end, ListNode** left, ListNode** right){

    ListNode* fast = start, *slow = start;
    int len = 0;
    
    //When this terminates slow is the middle of the list
    while(fast != end && fast->next != end){
        fast = fast->next->next;
        slow = slow->next;
        len += 2;
    }

    len += fast != end;

    *left = start;
    *right = slow;

    return len;
}


TreeNode* _solution(ListNode* start, ListNode* end){
    TreeNode* root = nullptr;
    ListNode *right, *left;

    int len = split_list(start, end, &left, &right);

    if(len == 0){
        return nullptr;
    }

    if(len == 1){
        return new TreeNode(left->val);
    }

    root = new TreeNode(right->val);
    root->left = _solution(left, right);
    root->right = _solution(right->next, end);
    
    return root;
}

TreeNode* solution(ListNode* A){
    return _solution(A, nullptr);
}

TEST(TreeToBstSuite, example) { 
    ListNode nodes[3] { 1, 2, 3 };
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];

    TreeNode expected[3] {1, 2, 3};
    expected[1].left = &expected[0];
    expected[1].right = &expected[2];

    ASSERT_TRUE(compare_tree_by_val(&expected[1], solution(&nodes[0]) ));
}

TEST(TreeToBstSuite, trivial_1) { 
    ListNode nodes[1] { 1 };

    TreeNode expected[1] { 1 };

    ASSERT_TRUE(compare_tree_by_val(&expected[0], solution(&nodes[0]) ));
}

TEST(TreeToBstSuite, trivial_0) { 

    ASSERT_TRUE(compare_tree_by_val(nullptr, solution(nullptr) ));
}

TEST(TreeToBstSuite, trivial_2) { 
    ListNode nodes[2] { 1, 2 };
    nodes[0].next = &nodes[1];

    TreeNode expected[2] { 1, 2 };
    expected[1].left = &expected[0];

    ASSERT_TRUE(compare_tree_by_val(&expected[1], solution(&nodes[0]) ));
}


TEST(TreeToBstSuite, complex) { 
    ListNode nodes[6] { 1, 2, 3, 4, 5, 6 };
    for(int i = 0; i < sizeof(nodes) / sizeof(ListNode) - 1; ++i){
        nodes[i].next = &nodes[i + 1];
    }

    TreeNode expected[6] {1, 2, 3, 4, 5, 6};
    expected[3].left = &expected[1];
    expected[3].right = &expected[5];

    expected[1].left = &expected[0];
    expected[1].right = &expected[2];

    expected[5].left = &expected[4];
    expected[4].right = nullptr;


    ASSERT_TRUE(compare_tree_by_val(&expected[3], solution(&nodes[0]) ));
}

TEST(TreeToBstSuite, complex_1) { 
    ListNode nodes[5] { 1, 2, 3, 4, 5 };
    for(int i = 0; i < sizeof(nodes) / sizeof(ListNode) - 1; ++i){
        nodes[i].next = &nodes[i + 1];
    }

    TreeNode expected[5] {1, 2, 3, 4, 5 };
    expected[2].left = &expected[1];
    expected[2].right = &expected[4];

    expected[1].left = &expected[0];
    expected[1].right = nullptr;

    expected[4].left = &expected[3];

    ASSERT_TRUE(compare_tree_by_val(&expected[2], solution(&nodes[0]) ));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}