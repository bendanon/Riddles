//  #include <gtest/gtest.h>
#include <array>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class ListNode{

public:
    ListNode();

    ListNode(T val);

    inline bool operator==(const ListNode<T>& other) const;

    inline bool operator==(const std::list<T>& lst) const; 

    inline bool operator!=(const std::list<T>& lst) const;

    static ListNode* FromList(const std::list<T>& lst);

    static void DeleteList(ListNode* plst);

    ~ListNode();

public:
    T value;
    ListNode *next;
};

template<class T>
ListNode<T>::ListNode(){
        next = nullptr;   
}

template<class T>
ListNode<T>::ListNode(T val){
        next = nullptr;
        value = val;
}

template<class T>
ListNode<T>::~ListNode(){

}

template<class T>
bool ListNode<T>::operator==(const ListNode<T>& other) const { 
    return other.value == value;
}

template<class T>
bool ListNode<T>::operator==(const std::list<T>& lst) const { 

        if(lst.empty() || this->value != lst.front()){
            return false;
        }

        ListNode* pit = next;
        return all_of(++begin(lst), end(lst),[&pit](T n){
            if(pit == nullptr || n != pit->value)
                return false;

            pit = pit->next;
            return true;
        });
}

template<class T>
bool ListNode<T>::operator!=(const std::list<T>& lst) const{
        return !(*this == lst);        
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