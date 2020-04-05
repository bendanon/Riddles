#include "ListNode.h"

template<class T>
ListNode<T>::ListNode(){
        next = nullptr;   
}

template<class T>
bool ListNode<T>::operator==(const ListNode<T>& other) const{ 
    return other.value == value;
}

template<class T>
bool ListNode<T>::operator==(const std::list<T>& lst) const { 

        const ListNode* pit = this;
        for(int n : lst){
            if(pit == nullptr || n != pit->value)
                return false;

            pit = pit->next;
        }

        return true;
}

template<class T>
bool ListNode<T>::operator!=(const std::list<T>& lst) const{
        return !(*this == lst);        
}

template<class T>
ListNode<T>* ListNode<T>::Reverse(ListNode<T>* A){

    ListNode *prev = nullptr, *current = A, *next = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

template<class T>
ListNode<T>* ListNode<T>::FromList(const std::list<T>& lst){
    ListNode<T> *head = new ListNode<T>();
    ListNode<T> *pit = head;

    for(int n : lst){
        pit->next = new ListNode<T>();
        pit->next->value = n;
        pit = pit->next;
    }

    pit = head->next;
    delete head;
    return pit;
}

template<class T>
void ListNode<T>::DeleteList(ListNode<T>* plst){
    ListNode<T> *pit = plst;
    ListNode<T> *pprev = nullptr;

    while(pit != nullptr){
        pprev = pit;
        pit = pit->next;
        delete pprev;
    }
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
    ListNode<int>* result = ListNode<int>::Reverse(input);
    ASSERT_EQ(*result, expected);
    ListNode<int>::DeleteList(result);
}
 
int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}