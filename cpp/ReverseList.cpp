#include <gtest/gtest.h>
#include "ListNode.h"

template<class T>
ListNode<T>* solution(ListNode<T>* A){

    ListNode<T> *prev = nullptr, *current = A, *next = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

TEST(LinkedListTestSuite, BasicTestPositive) {
    std::list<float> expected = {1,2,3};
    std::list<float> _result = {1,2,3};
    ListNode<float>* result = ListNode<float>::FromList(_result);
    ASSERT_EQ(*result, expected);
    ListNode<float>::DeleteList(result);
}

TEST(LinkedListTestSuite, BasicTestNegative) {
    std::list<int> expected = {1,2,3};
    std::list<int> _result = {1,3,3};
    ListNode<int>* result = ListNode<int>::FromList(_result);
    ASSERT_TRUE(*result != expected);
    ListNode<int>::DeleteList(result);
}

TEST(ReverseListTestSuite, Basic){
    std::list<int> expected = {1, 2, 3};
    std::list<int> _input = {3, 2, 1};
    ListNode<int>* input = ListNode<int>::FromList(_input);
    ListNode<int>* result = solution<int>(input);
    ASSERT_EQ(*result, expected);
    ListNode<int>::DeleteList(result);
}
 
int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}