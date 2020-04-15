#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

/**
 * A linked list is given such that each node contains an 
 * additional random pointer which could point to any node in the list or NULL.
 * Return a deep copy of the list. 
 * The returned answer should not contain the same node as the original list, but a copy of them. 
 * The pointers in the returned list should not link to any node in the original input list.
 * */ 

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode* solution(RandomListNode* A){

    RandomListNode* head = A;
    unordered_map<RandomListNode*, RandomListNode*> original_to_copy;

    //Allocate copy and set values    
    while(head){
        original_to_copy[head] = new RandomListNode(head->label);
        head = head->next;
    }

    head = A;
    
    while(head){
        original_to_copy[head]->next = original_to_copy[head->next];
        original_to_copy[head]->random = original_to_copy[head->random];
        head = head->next;
    }

    return original_to_copy[A];
}


void compare(RandomListNode* original, RandomListNode* copy){
    RandomListNode* curr = original;
    RandomListNode* sol = copy;

    while(curr != nullptr && sol != nullptr){
        //std::cout << "->" << curr->label << "\n";
        
        ASSERT_EQ(curr->label, sol->label);
        
        if(curr->random == nullptr){
            ASSERT_TRUE(sol->random == nullptr);
        } else{
            ASSERT_EQ(curr->random->label, sol->random->label);
            ASSERT_NE(curr->random, sol->random);
        }
        ASSERT_NE(curr, sol);
        
        curr = curr->next;
        sol = sol->next;
    }
}

TEST(CopyListSuite, Example) {
    RandomListNode nodes [3] {1, 2, 3};
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = nullptr;
 
    nodes[0].random = &nodes[2];
    nodes[1].random = &nodes[0];
    nodes[2].random = &nodes[0];

    compare(&nodes[0], solution(&nodes[0]));
    
}

TEST(CopyListSuite, Trivial_1) {
    RandomListNode nodes [1] {1};
    nodes[0].next = nullptr;
    nodes[0].random = &nodes[0];
 
    compare(&nodes[0], solution(&nodes[0]));
}

TEST(CopyListSuite, Trivial_0){
    ASSERT_EQ(nullptr, solution(nullptr));
}

TEST(CopyListSuite, Trivial_2){
    RandomListNode nodes [3] {1, 2, 3};
    nodes[0].next = &nodes[1];
    nodes[1].next = nullptr;
 
    nodes[0].random = &nodes[1];
    nodes[1].random = &nodes[0];

    compare(&nodes[0], solution(&nodes[0]));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}