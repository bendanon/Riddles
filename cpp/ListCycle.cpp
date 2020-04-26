#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
*/

template<class T>
size_t cycle_length(ListNode<T>* A){
    if(A == nullptr || A->next == nullptr){
        return 0;
    }

    auto slow = A;
    auto fast = A;
    
    while(fast != nullptr && fast->next != nullptr) { 
        fast = fast->next->next; 
        slow = slow->next;
        
        //This means a cycle
        if(slow == fast){

            //Count the number of elements in the cycle
            fast = fast->next;
            size_t counter = 1;
            while(fast != slow){ 
                ++counter;
                fast = fast->next;
            }
            return counter;
        }
    }

    return 0;
}

template<class T>
ListNode<T>* solution(ListNode<T>* A){

    size_t cyc_len = cycle_length(A);
    if(cyc_len == 0){
        return nullptr;
    }

    auto back = A;
    auto front = A;

    //Advance the front cyc_length steps forward
    for(int i = 0; i < cyc_len; ++i) { front = front->next; }

    //Front will reach the first node at the same time as back
    while(front != back) { front = front->next; back = back->next; }

    return front;
}

template<class T>
ListNode<T> *detectCycle(ListNode<T> *head) {
        if (head == NULL || head->next == NULL) return NULL;

        auto firstp = head;
        auto secondp = head;
        bool isCycle = false;

        while(firstp != NULL && secondp != NULL) {
            firstp = firstp->next;
            if (secondp->next == NULL) return NULL;
            secondp = secondp->next->next;
            if (firstp == secondp) { isCycle = true; break; }
        }

        if(!isCycle) return NULL;
        firstp = head;
        while( firstp != secondp) {
            firstp = firstp->next;
            secondp = secondp->next;
        }

        return firstp;
}

TEST(LinkedListTestSuite, Example) {
    ListNode<float> nodes[4] = {1, 2, 3, 4};
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    nodes[3].next = &nodes[2];

    ASSERT_EQ(&nodes[2], solution(nodes));
}

TEST(LinkedListTestSuite, Fail) {
    ListNode<float> nodes[5] = {1, 2, 3, 4, 5};
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    nodes[3].next = &nodes[4];
    nodes[4].next = &nodes[2];

    ASSERT_EQ(&nodes[2], detectCycle(nodes));
}

TEST(LinkedListTestSuite, LargerCycle) {
    ListNode<float> nodes[4] = {1, 2, 3, 4};
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    nodes[3].next = &nodes[1];

    ASSERT_EQ(&nodes[1], solution(nodes));
}

TEST(LinkedListTestSuite, FullCycle) {
    ListNode<float> nodes[4] = {1, 2, 3, 4};
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    nodes[3].next = &nodes[0];

    ASSERT_EQ(&nodes[0], solution(nodes));
}

TEST(LinkedListTestSuite, Trivial) {
    ListNode<float> nodes[4] = {1, 2, 3, 4};
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];

    ASSERT_EQ(nullptr, solution(nodes));
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}