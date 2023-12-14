//
// Created by rakin on 12/14/2023.
//

#ifndef HEAP_ALLOCATOR_LINKEDLIST_H
#define HEAP_ALLOCATOR_LINKEDLIST_H

/**
 * @brief A custom implementation of linked list.
 * @tparam T Type
 */
template<class T>
class LinkedList {
public:
private:
    struct Node {
        T data{};
        Node *next{};
    };

    Node *head{};
    Node *tail{};
};

#endif //HEAP_ALLOCATOR_LINKEDLIST_H
