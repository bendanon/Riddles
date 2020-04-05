#include <gtest/gtest.h>
#include <array>
#include <list>
#include <iostream>

template<class T>
class ListNode{

public:
    ListNode();
    inline bool operator==(const ListNode<T>& other) const;

    inline bool operator==(const std::list<T>& lst) const; 

    inline bool operator!=(const std::list<T>& lst) const;

    static ListNode* Reverse(ListNode* A);

    static ListNode* FromList(const std::list<T>& lst);

    static void DeleteList(ListNode* plst);

public:
    T value;
    ListNode *next;
};